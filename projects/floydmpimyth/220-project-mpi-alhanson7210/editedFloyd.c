/*

Students:
	Jacob Hanicak
	Alex Hanson

Project:
	MPI Myth

Date:
	5/5/2019
 
*/

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
void copyMatrix(int * globalMatrix, int * localMatrix, int row);
int min(int matrixValue, int computedCost);
/*
 *DRIVER
 */
int main(void) {
	//instance variables
	int processes, correctMatrix, row = 0, column = 0, rank, *globalMatrix = NULL, *localMatrix = NULL, *localRow = NULL;
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

	MPI_Barrier(communicator);
	//broadcast row and column to all the processes
	MPI_Bcast(&row, 1, MPI_INT, SOURCE, communicator);
	MPI_Bcast(&column, 1, MPI_INT, SOURCE, communicator);

	//allocate space for the matrix
	globalMatrix = malloc(row*column*sizeof(int));
	localMatrix = malloc(row*column*sizeof(int));

	MPI_Barrier(communicator);
	if(rank == SOURCE)
		//read in matrix values
		scanMatrix(globalMatrix, row, column);

	MPI_Barrier(communicator);

	//broadcast the intial matrix to other processes
	MPI_Bcast(globalMatrix, row*row,MPI_INT, SOURCE, communicator);

        //copy the global matrix to the local matrix
        copyMatrix(globalMatrix, localMatrix, row);

	//space for designated row
	localRow = malloc(column*sizeof(int));
	
	MPI_Barrier(communicator);
	//computing floyds algorithm
	for(correctMatrix = 0; correctMatrix < row; correctMatrix++) {
		//print matrix
		if(rank == SOURCE) printMatrix(globalMatrix, row, column);

	        MPI_Barrier(communicator);

		//scatter the respective row
		(rank == SOURCE)? MPI_Scatter(localMatrix, row,MPI_INT,localRow,row,MPI_INT,SOURCE,communicator) : MPI_Scatter(localMatrix, row,MPI_INT,localRow,row,MPI_INT, SOURCE,communicator);
		
		MPI_Barrier(communicator);

		//correct Matrix
		floydAlogrithm(globalMatrix,localRow,row, column, correctMatrix, rank);
		
		//gather the corrected
		(rank == SOURCE)? MPI_Gather(localRow,row,MPI_INT,localMatrix,row*column,MPI_INT,SOURCE,communicator) : MPI_Gather(localRow,row,MPI_INT,localMatrix,row*column,MPI_INT,SOURCE,communicator);

		MPI_Barrier(communicator);

		//copy local matrix to global matrix
		copyMatrix(localMatrix, globalMatrix, row);
	}
	//print matrix
	if(rank == SOURCE) printMatrix(localMatrix, row, column);

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
	int r, c, Min;
	for (r = 0; r < row; r++) {
		for(c = 0; c < column; c++) {
			if(r == rank && r != vertex && c != vertex && r != c) {
				Min =min(localRow[r], globalMatrix[r*vertex+c] + globalMatrix[vertex*c+r]);
				//printf("\nmin is %d.\n", Min);
				localRow[r] = Min;
			}
		}
	}
}

void scanMatrix(int *globalMatrix, int row, int column) {
	int r, c;
	for(r = 0;r < row; r++)
		for(c = 0; c < column; c++)
			(r == c)? globalMatrix[r*column+c] = INFINITY :scanf("%d", &globalMatrix[r*column+c]);
}

void printMatrix(int *globalMatrix, int row, int column) {
	int r, c;
	printf("\n");
        for(r = 0;r < row; r++){
		for(c = 0; c < column; c++)
			(r == c)? printf("%s\t", "∞") : printf("%d\t", globalMatrix[r*column+c]);
		printf("\n");
	}
}

int min(int matrixValue, int computedCost){
	if(matrixValue == INFINITY && computedCost > INFINITY) return INFINITY;
	return (matrixValue < computedCost)? matrixValue : computedCost;
}

void copyMatrix(int * Matrix, int * matrix, int row) {
	int r, c;
        for(r = 0;r < row; r++)
                for(c = 0; c < row; c++)
			matrix[r*row+c] = Matrix[r*row+c];
}
//∞
//œ∑´®†\¨ˆøß∂ƒ©˙˚√˙∆√˙∆˚ˆª•§∞¢£™
