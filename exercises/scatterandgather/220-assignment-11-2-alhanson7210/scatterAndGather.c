/*Parallel Program*/
//LIBRARIES
#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
//DRIVER
int main(void) {
	int i, processors, rank, destination, source, sendtag = 0, recvtag = 0, pieces, *list, *shiftedList, *unscatteredList;

	MPI_Comm communicator;

	MPI_Init(NULL,NULL);

	communicator = MPI_COMM_WORLD;

	MPI_Comm_size(communicator, &processors);
	MPI_Comm_rank(communicator, &rank);
	if(rank == 0) printf("%d needed random numbers: ", processors);

	destination = (rank + 1) % processors;
	source = (rank - 1 + processors) % processors;
	pieces = (int)(processors/processors);

	list = malloc( processors * sizeof(int) );
	shiftedList = malloc( pieces * sizeof(int) );
	unscatteredList = malloc(pieces * sizeof(int));
	int * global_list = malloc( processors * sizeof(int) );
	if(rank == 0) {
		//printf("%d needed random numbers: ", processors);
		for(i = 0; i < processors; i++) {
			printf("\n%d out of %d needed random numbers: ", i+1, processors);
			scanf("%d", &list[i]);
		}
	        /*MPI_Scatter(list, pieces, MPI_INT, unscatteredList, pieces, MPI_INT, 0, communicator);
		free(list);*/
	}
	MPI_Scatter(list, pieces, MPI_INT, unscatteredList, pieces, MPI_INT, 0, communicator);
	free(list);
	MPI_Sendrecv(unscatteredList, 1, MPI_INT, destination, sendtag, shiftedList, 1, MPI_INT, source, recvtag, communicator, 0);
	free(unscatteredList);
	MPI_Gather(shiftedList, pieces, MPI_INT, global_list, pieces, MPI_INT, 0, communicator);
	free(shiftedList);
	if(rank == 0) {
		printf("\nShifted list:");
		for(i = 0; i < processors; i++) {
			printf(" %d", global_list[i]);
		}
		printf("\n");
	}
	free(global_list);
	MPI_Finalize();
	return 0;
}
/*END OF THE PROGRAM*/
