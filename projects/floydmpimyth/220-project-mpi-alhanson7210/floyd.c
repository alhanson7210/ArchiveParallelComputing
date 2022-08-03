/*
 *LIBRARIES
 */
#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
/*
 *CONSTANTS
 */
const int INFINITY = 1000000;
const int NEGATIVEINFINITY = -1000000;
const int SOURCE = 0;
/*
 *PROTOTYPES
 */
void floydAlogrithm(int *globalMatrix, int *localRow, int row, int column, int vertex, int rank);
void scanMatrix(int *globalMatrix, int row, int column);
void printMatrix(int *globalMatrix, int row, int column);
int min(int matrixValue, int computedCost);
/*
 *DRIVER
 */
int main(void) {
	//instance variables
	int processes, correctMatrix, row = 0, column = 0, rank, *globalMatrix, *localRow;
	MPI_Comm communicator;
	
	//setup of MPI
	MPI_Init(NULL, NULL);
	communicator = MPI_COMM_WORLD;
	MPI_Comm_size(communicator, &processes);
	MPI_Comm_rank(communicator, &rank);
	
	//scan in matrix and row,column
	if(rank == SOURCE) {
		//get row for the matrix
		printf("\nEnter row length: ");
		scanf("%d", &row);
		while(row < processes) {
			printf("\nThe row size has to be divisble by the amoount of processes given by the command line.\nPlease enter the row length: ");
                	scanf("%d", &row);
		}
		
		//get the column for the matrix
		column = row;
		
	}
	//broadcast row and column to all the processes
	MPI_Bcast(&row, 1, MPI_INT, SOURCE, communicator);
	MPI_Bcast(&column, 1, MPI_INT, SOURCE, communicator);

	//allocate space for the matrix
	globalMatrix = malloc(row*column*sizeof(int));

	if(rank == SOURCE)
		//read in matrix values
		scanMatrix(globalMatrix, row, column);

	//broadcast the intial matrix to other processes
	MPI_Bcast(&globalMatrix, row*column,MPI_INT, SOURCE, communicator);
	
	//space for designated row
	localRow = malloc(column*sizeof(int));

	//computing floyds algorithm
	for(correctMatrix = 0; correctMatrix < row; correctMatrix++) {
		//print matrix
		if(rank == SOURCE) printMatrix(globalMatrix, row, column);

		//scatter the respective row
		(rank == SOURCE)? MPI_Scatter(&globalMatrix, (row*column)/processes,MPI_INT,&localRow,(row*column)/processes,MPI_INT,SOURCE,communicator) : MPI_Scatter(&globalMatrix, (row*column)/processes,MPI_INT,&localRow,(row*column)/processes,MPI_INT, SOURCE,communicator);
		
		//correct Matrix
		floydAlogrithm(globalMatrix,localRow,row, column, correctMatrix, rank);
		
		//gather the corrected 
		(rank == SOURCE)? MPI_Gather(&localRow,(row*column)/processes,MPI_INT,&globalMatrix,(row*column)/processes,MPI_INT,SOURCE,communicator) : MPI_Gather(&localRow,(row*column)/processes,MPI_INT,&globalMatrix,(row*column)/processes,MPI_INT,SOURCE,communicator);		
	}
	//print matrix
	if(rank == SOURCE) printMatrix(globalMatrix, row, column);

	//free space used and close MPI environment
	MPI_Finalize();
	free(globalMatrix);
	free(localRow);

	//return default value
	return 0;
}
/*
 *FUNCTION DECLARATIONS
 */
void floydAlogrithm(int *globalMatrix, int *localRow, int row, int column, int vertex, int rank) {
	for (int r = 0; r < row; r++)
		for(int c = 0; c < column; c++)
			if(r == rank && r != vertex && c != vertex && r != c) 
				globalMatrix[r*column+c] = min(globalMatrix[r*column+c], globalMatrix[r*vertex+c]+ globalMatrix[vertex*c+r]);
}

void scanMatrix(int *globalMatrix, int row, int column) {
	for(int r = 0;r < row; r++)
		for(int c = 0; c < column; c++)	
			(r == c)? globalMatrix[r*column+c] = INFINITY :scanf("%d", &globalMatrix[r*column+c]);	
}

void printMatrix(int *globalMatrix, int row, int column) {
        for(int r = 0;r < row; r++) 
		for(int c = 0; c < column; c++) 
			(r == c)? printf("%s", "∞") : printf("%5d", globalMatrix[r*column+c]);
}
int min(int matrixValue, int computedCost){
	if(matrixValue == INFINITY && computedCost > INFINITY) return INFINITY;
	return (matrixValue < computedCost)? matrixValue : computedCost;
}
//∞
//œ∑´®†\¨ˆøß∂ƒ©˙˚√˙∆√˙∆˚ˆª•§∞¢£™
