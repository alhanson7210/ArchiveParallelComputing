#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
int main(void){
	int i, sum = 0, destination, source, tag = 0, randomInt, processes, rank;
	MPI_Comm communicator;
	MPI_Init(NULL,NULL);
	communicator = MPI_COMM_WORLD;
	MPI_Comm_size(communicator, &processes);
	MPI_Comm_rank(communicator, &rank);
	srandom(rank);
	randomInt = random() % 20;
	for(i = 0; i < processes; i++) {
		sum += randomInt;
		printf("In Iteration %d for Process %d out of %d processes, the sum equates to %d.\n", i, rank+1, processes, sum);
		destination = (rank + 1)%processes;
		source = (rank - 1 + processes)%processes;
		MPI_Send(&randomInt,1,MPI_INT,destination,tag,communicator);
		MPI_Recv(&randomInt,1,MPI_INT,source, tag, communicator, MPI_STATUS_IGNORE);
	}
	printf("Process %d's sum equates to %d.\n", rank, sum);
	MPI_Finalize();
}
