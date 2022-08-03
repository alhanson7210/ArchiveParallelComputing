//Jake Hanicak
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
void intitializeBoard(int board[9][9], int ninjaBoard[9][9]);
void start(int board[9][9], int ninjaBoard[9][9]);
void createSudokuPuzzle(int board[9][9], int ninjaBoard[9][9]);
void display(int board[9][9]);
void addInitialValue(int board[9][9], int ninjaBoard[9][9], int row, int col, int value);
void addGuess(int board[9][9], int ninjaBoard[9][9], int row, int col, int value);
bool checkPuzzle(int board[9][9], int ninjaBoard[9][9]);
int getValueIn(int board[9][9], int row, int col);
int * getAllowedValues(int board[9][9], int row, int col);
bool isFull(int ninjaBoard[9][9]);
void reset(int board[9][9], int ninjaBoard[9][9]);
void displaySingleArray(int arr[], int n);
void initializeCounterArray(int counterArray[9]);
bool checkRowAndColumn(int board[9][9], int row, int col, int value);
bool checkGrid(int board[9][9], int row, int col);
void randomizedSudokuPuzzle(int board[9][9], int ninjaBoard[9][9]);
void directions();
bool duplicity(int board[9][9], int row, int col, int value);

void displaySingleArray(int arr[], int n) {
  for(int i = 0; i < n; i++) {
    printf("arr[%d] is %d.\t", i, arr[i]);
  }
}

void initializeCounterArray(int counterArray[9]) {
	for(int i = 0; i < 9; i++)
		counterArray[i] = 0;
}

void intitializeBoard(int board[9][9], int ninjaBoard[9][9]) {
	for(int row = 0; row < 9; row++) {
		for(int col = 0; col < 9; col++) {
			board[row][col] = 0;
			ninjaBoard[row][col] = 0;
		}
	}
}

void start(int board[9][9], int ninjaBoard[9][9]) {
	intitializeBoard(board, ninjaBoard);
	//createSudokuPuzzle(board,ninjaBoard);
}

void randomizedSudokuPuzzle(int board[9][9], int ninjaBoard[9][9]) {
	srand(time(NULL));
	int counter = 36;
	while (counter != 0) {
		int row = rand()%9, col = rand()%9, value = rand()%9+1;
		int position = getValueIn(ninjaBoard, row, col);
		printf("\n%d %d %d %d\n", row,col,value,position);
		while(!duplicity(board,row,col,value) && !checkRowAndColumn(board,row,col,value && position != 0)) {
                	row = rand()%9;
                        col = rand()%9;
                        value = rand()%9 + 1;
                        position = getValueIn(ninjaBoard, row, col);
			printf("\n%d %d %d %d\n", row,col,value,position);
		}
		addInitialValue(board, ninjaBoard, row, col, value);
		counter--;
	}
}
bool checkRowAndColumn(int board[9][9], int row, int col, int value){
	//rows
	int colArray[9], rowArray[9];
	for(int i = 0; i < 9; i++){
		colArray[i] = 0;
		rowArray[i] = 0;
	}

	for(int j = 0; j < 9; j++) {
		if(board[row][j] != 0)
			colArray[board[row][j]-1]++;

		else if(board[row][j] == 0 && j == col)
			colArray[value-1]++;

		if(board[j][col] != 0)
			rowArray[board[j][col]-1]++;

		else if(board[j][col] == 0 || j == row)
			rowArray[value-1]++;

	}
	for(int g = 0; g < 9; g++) {
		if(colArray[g] > 1)
			return false;
		if(rowArray[g] > 1)
			return false;
	}
	return true;
	/*
	for(int x = 0; x < 9; x++){
		if(getValueIn(board,row,x) == value) {
			z++;
			if(z==1)
				return false;
		}
    	}
        //columns
    	for(int y = 0; y < 9; y++){
		if(getValueIn(board,y,col) == value) {
			z++;
			if(z==1)
				return false;
		}
    	}
	return true;
	*/
}
void createSudokuPuzzle(int board[9][9], int ninjaBoard[9][9]) {
	addInitialValue(board, ninjaBoard, 0, 1, 6);
	addInitialValue(board, ninjaBoard, 0, 2, 8);
	addInitialValue(board, ninjaBoard, 0, 6, 9);
	addInitialValue(board, ninjaBoard, 0, 7, 3);
	addInitialValue(board, ninjaBoard, 1, 1, 4);
	addInitialValue(board, ninjaBoard, 1, 2, 2);

    addInitialValue(board, ninjaBoard, 1, 6, 6);
    addInitialValue(board, ninjaBoard, 2, 0, 1);
    addInitialValue(board, ninjaBoard, 2, 1, 9);
    addInitialValue(board, ninjaBoard, 2, 4, 8);
    addInitialValue(board, ninjaBoard, 2, 7, 4);
    addInitialValue(board, ninjaBoard, 3, 1, 8);

    addInitialValue(board, ninjaBoard, 3, 2, 5);
    addInitialValue(board, ninjaBoard, 3, 3, 2);
    addInitialValue(board, ninjaBoard, 3, 5, 1);
    addInitialValue(board, ninjaBoard, 3, 8, 7);
    addInitialValue(board, ninjaBoard, 4, 0, 7);
    addInitialValue(board, ninjaBoard, 4, 3, 8);

    addInitialValue(board, ninjaBoard, 4, 4, 9);
    addInitialValue(board, ninjaBoard, 5, 0, 2);
    addInitialValue(board, ninjaBoard, 5, 2, 9);
    addInitialValue(board, ninjaBoard, 5, 5, 7);
    addInitialValue(board, ninjaBoard, 5, 6, 5);
    addInitialValue(board, ninjaBoard, 5, 8, 3);

    addInitialValue(board, ninjaBoard, 6, 1, 2);
    addInitialValue(board, ninjaBoard, 6, 3, 1);
    addInitialValue(board, ninjaBoard, 6, 7, 5);
    addInitialValue(board, ninjaBoard, 7, 0, 8);
    addInitialValue(board, ninjaBoard, 7, 1, 5);
    addInitialValue(board, ninjaBoard, 7, 4, 4);

    addInitialValue(board, ninjaBoard, 7, 6, 7);
    addInitialValue(board, ninjaBoard, 7, 7, 6);
    addInitialValue(board, ninjaBoard, 8, 0, 4);
    addInitialValue(board, ninjaBoard, 8, 1, 7);
    addInitialValue(board, ninjaBoard, 8, 2, 3);
    addInitialValue(board, ninjaBoard, 8, 4, 5);

	addInitialValue(board, ninjaBoard, 8, 5, 2);
	addInitialValue(board, ninjaBoard, 8, 8, 9);
}

void display(int board[9][9]) {
    for(int row = 0; row < 9; row++) {
        for(int col = 0; col < 9; col++)
            printf("%3d\t", board[row][col]);
	printf("\n");
    }
}

void addInitialValue(int board[9][9], int ninjaBoard[9][9], int row, int col, int value) {
	board[row][col] = value;
	ninjaBoard[row][col] = -1;
}

void addGuess(int board[9][9], int ninjaBoard[9][9], int row, int col, int value) {
	if(getValueIn(ninjaBoard,row,col) > -1) {
		board[row][col] = value;
		ninjaBoard[row][col] = 1;
	}
}
bool checkGridPattern(int board[9][9], int row, int col, int value){
        int rowArray[3], colArray[3];
        //initialize row counter for given value
        for(int j = 0; j < 3; j++){
                rowArray[j] = 0;
                colArray[j] = 0;
        }
        //counting the occurences of the value in row
	int z = 0;
        for(int r= row; r <= row+2; r++){
                for(int i = 0; i < 9; i++){
                        if(board[r][i] == value)
                                rowArray[z]++;
				

                }
		z++;
        }
        //checking if there is only one occurence of a given value in all rows
        for(int j = 0; j < 3; j++){
                if(rowArray[j] > 1)
                        return false;
        }
        //counting the occurences of the value in col
	z = 0;
        for(int c= col; c <= col+2; c++){
                for(int i = 0; i < 9; i++){
                        if(board[i][c] == value)
                                colArray[z]++;
                }
		z++;
        }
        //checking if there is only one occurence of a given value in all cols
        for(int j = 0; j < 3; j++){
                if(colArray[j] > 1)
                        return false;
        }
        //one grid check has been successfully made for a given value
        return true;
}
//three checks of grid sized row and columns for a value
bool checkPattern(int board[9][9], int value) {
        bool patternCheck;
        //completes 1st, 2nd, and 3rd grid checks for a given value
        for(int x = 0; x <= 6; x+=3){
                patternCheck = checkGridPattern(board,x,x,value);
                if(!patternCheck)
                        return false;
        }
        return patternCheck;
}
//checks all grids for duplicates or if the filled board is correct
bool modifiedCheckPuzzle(int board[9][9], int ninjaBoard[9][9]){
        //checking the grid
        if(!isFull(ninjaBoard)){
                for(int x = 0; x <= 6; x+=3){
                        for(int y = 0; y <= 6; y+=3){
                                if(checkGrid(board,x,y) == false)
                                        return false;
                        }
                }
                return true;
        }
        else{
                bool correctBoard;
                for(int i = 1; i <= 9; i++) {
                        correctBoard = checkPattern(board,i);
                        if(!correctBoard)
                                return false;
                }
                return correctBoard;
        }
}

bool checkGrid(int board[9][9], int row, int col) {
	int countingArray[9];
    initializeCounterArray(countingArray);
	for(int r= row; r <= row+2; r++){
		for(int c= col; c <= col+2; c++){
			int cell = getValueIn(board,r,c);
            if(cell != 0)
            	countingArray[cell-1]++;
		}
	}
	for(int i = 0; i < 9; i++){        
        if(countingArray[i] > 1)
        	return false;
    }
	return true;
}

bool checkPuzzle(int board[9][9], int ninjaBoard[9][9]) {
	//checking the grid
	if(!isFull(ninjaBoard)){
		for(int x = 0; x <= 6; x+=3){
			for(int y = 0; y <= 6; y+=3){
				if(checkGrid(board,x,y) == false)
					return false;
			}
		}
	}
	//checking all rows and columns
	else{
		for(int row = 0; row < 9; row++) {
			int countingArray[9];
			//counting the occurences in the column
			initializeCounterArray(countingArray);
            for(int col = 0; col < 9; col++){
				int cell = getValueIn(board,row,col);
				if(cell != 0)
					countingArray[cell-1]++;
			}
			for(int i = 0; i < 9; i++){
				if(countingArray[i] > 1)
					return false;
			}
			//counting the occuences in the row
			initializeCounterArray(countingArray);
        	for(int col = 0; col < 9; col++){
        	    int cell = getValueIn(board,col,row);
        	    if(cell != 0)
        	    	countingArray[cell-1]++;
        	}
        	for(int i = 0; i < 9; i++){
        	    if(countingArray[i] > 1)
        	    	return false;
        	}
		}
		return true;
	}
	return true;
}

bool grid(int board[9][9], int row, int col, int value) {
	int count = 0;
	for(int r= row; r <= row+2; r++){
                for(int c= col; c <= col+2; c++){
			if(getValueIn(board,r,c) == value)
                		count++;
                }
        }
        if(count == 0)
		return true;
	return false;
}

int * checkForCorner(int board[9][9], int row, int col) {
	int cnr[2];

	if(row < 3 && col < 3)
		cnr[0] = 0, cnr[1] = 0; //{0,0}

	else if(row < 3 && col >= 3 && col < 6)
		cnr[0] = 0, cnr[1] = 3; //{0,3}

	else if(row < 3 && col >= 6)
		cnr[0] = 0, cnr[1] = 6; //{0,6}

        else if(row >= 3 && row < 6 && col < 3)
		cnr[0] = 3, cnr[1] = 0;//{3,0};

        else if(row >= 3 && row < 6 && col >= 3 && col < 6)
		cnr[0] = 3, cnr[1] = 3;//{3,3};

        else if(row >= 3 && row < 6 && col >= 6)
		cnr[0] = 3, cnr[1] = 6;//{3,6};

        else if(row >= 6 && col < 3)
		cnr[0] = 6, cnr[1] = 0;//{6,0};

        else if(row >= 6 && col >= 3 && col < 6)
		cnr[0] = 6, cnr[1] = 3;//{6,3};

        else if(row >= 6 && col >= 6)
		cnr[0] = 6, cnr[1] = 6;//{6,6};
	
	int * c = cnr;
	return c;
} 

bool duplicity(int board[9][9], int row, int col, int value) {
	int *corner = checkForCorner(board, row, col);
	return grid(board, *corner, *(corner+1),value);
}

int getValueIn(int board[9][9], int row, int col) {
	return board[row][col];
}

int * getAllowedValues(int board[9][9], int row, int col) {
	int collinderArray[17], countingArray[9], unduplicatedArray[9];
	static int temp[10];//This is static to make it a global variable so it would have its own location in memory
	for(int i = 0; i < 17; i++){
		if(i != 9){
			collinderArray[i]=0;
			countingArray[i]=0;
			unduplicatedArray[i]=0;
			temp[i]=0;
		}

		else if(i != 10){
			collinderArray[i]=0;
			temp[i]=0;
		}
		else{
			collinderArray[i]=0;
		}
	}
	collinderArray[0] = getValueIn(board, row, col);
	int counter = 1;
	while (counter < 17) {
		//rows
		for(int x = 0; x < 9; x++){
			if(x != row){
				collinderArray[counter] = getValueIn(board,x,col);
				counter++;
			}
		}
		//columns
		for(int y = 0; y < 9; y++){
			if(y != col){
				collinderArray[counter] = getValueIn(board,row,y);
				counter++;
			}
		}
	}
	for(int j = 0; j < 9; j++)
		countingArray[j] = 0;
	
	for(int i = 0; i < 17; i++) {
		countingArray[collinderArray[i]-1]++;
	}
	
	for(int z = 0; z < 9; z++){
		if(countingArray[z] > 0)
			unduplicatedArray[z] = z+1;
		else
			unduplicatedArray[z] = 0;
	}
	counter = 0;
	for(int f = 0; f < 9; f++){
		if(unduplicatedArray[f] == 0){
			temp[counter] = f+1;
			counter++;
		}
	}
	//bool checkForDuplicatesInGrid = duplicity
	temp[9] = counter; // last one will always be the size of the temp array, make its easier to manipulate
	return temp;
}

bool isFull(int ninjaBoard[9][9]) {
	for(int r = 0; r < 9; r++){
		for(int c = 0; c < 9; c++){
			if(getValueIn(ninjaBoard,r,c) == 0)
				return false;
		}
	}
	return true;
} 

void reset(int board[9][9], int ninjaBoard[9][9]) {
	intitializeBoard(board, ninjaBoard);
}

void directions(){
		printf("Your instructions are as follows:\n"
		"\n"
		"This is a classic take on sudoku"
		"1 - Each block (3X3) must have the numbers 1-9.\n"
		"2 - Each row and column must also have the numbers 1-9.\n"
		"3 - the numbers 1-9 in any block (3x3) or any row or column must not be repeated.\n"
		"\n"
		"Begin playing and have fun!\n");
}
/*
bool boardComparedToBoard(){

}*/
void createCorrectPuzzle(int boardd[9][9], int ninjaBoard[9][9]) {
	for(int row = 0; row < 9; row++) {
                for(int col = 0; col < 9; col++) {
                        boardd[row][col] = 0;
                }
        }
	addInitialValue(boardd, ninjaBoard, 0, 1, 6);
    	addInitialValue(boardd, ninjaBoard, 0, 2, 8);
        addInitialValue(boardd, ninjaBoard, 0, 6, 9);
        addInitialValue(boardd, ninjaBoard, 0, 7, 3);
	addInitialValue(boardd, ninjaBoard, 0, 0, 5);
	addInitialValue(boardd, ninjaBoard, 0, 3, 7);
	addInitialValue(boardd, ninjaBoard, 0, 4, 2);
	addInitialValue(boardd, ninjaBoard, 0, 5, 4);
	addInitialValue(boardd, ninjaBoard, 0, 8, 1);

        addInitialValue(boardd, ninjaBoard, 1, 1, 4);
	addInitialValue(boardd, ninjaBoard, 1, 0, 3);
	addInitialValue(boardd, ninjaBoard, 1, 3, 5);
	addInitialValue(boardd, ninjaBoard, 1, 4, 1);
	addInitialValue(boardd, ninjaBoard, 1, 5, 9);
	addInitialValue(boardd, ninjaBoard, 1, 7, 7);
        addInitialValue(boardd, ninjaBoard, 1, 2, 2);
    	addInitialValue(boardd, ninjaBoard, 1, 6, 6);
	addInitialValue(boardd, ninjaBoard, 1, 8, 8);
	
    	addInitialValue(boardd, ninjaBoard, 2, 0, 1);
    	addInitialValue(boardd, ninjaBoard, 2, 1, 9);
    	addInitialValue(boardd, ninjaBoard, 2, 4, 8);
    	addInitialValue(boardd, ninjaBoard, 2, 7, 4);
    	addInitialValue(boardd, ninjaBoard, 3, 1, 8);
	addInitialValue(boardd, ninjaBoard, 2, 2, 7);
	addInitialValue(boardd, ninjaBoard, 2, 3, 3);
	addInitialValue(boardd, ninjaBoard, 2, 5, 6);
	//addInitialValue(boardd, ninjaBoard, 2, 7, 2);
	addInitialValue(boardd, ninjaBoard, 2, 8, 5);
	addInitialValue(boardd, ninjaBoard, 2, 6, 2);
	addInitialValue(boardd, ninjaBoard, 3, 0, 6);
	addInitialValue(boardd, ninjaBoard, 3, 4, 3);
	addInitialValue(boardd, ninjaBoard, 3, 6, 4);
	addInitialValue(boardd, ninjaBoard, 3, 7, 9);
	addInitialValue(boardd, ninjaBoard, 4, 1, 3);
	addInitialValue(boardd, ninjaBoard, 4, 2, 4);
	addInitialValue(boardd, ninjaBoard, 4, 5, 5);
	addInitialValue(boardd, ninjaBoard, 4, 6, 1);
	addInitialValue(boardd, ninjaBoard, 4, 7, 2);
	addInitialValue(boardd, ninjaBoard, 4, 8, 6);
	addInitialValue(boardd, ninjaBoard, 5, 1, 1);
	addInitialValue(boardd, ninjaBoard, 5, 3, 4);
	addInitialValue(boardd, ninjaBoard, 5, 4, 6);
	addInitialValue(boardd, ninjaBoard, 5, 7, 8);
	addInitialValue(boardd, ninjaBoard, 6, 0, 9);
	addInitialValue(boardd, ninjaBoard, 6, 2, 6);
	addInitialValue(boardd, ninjaBoard, 6, 4, 7);
	addInitialValue(boardd, ninjaBoard, 6, 5, 8);
	addInitialValue(boardd, ninjaBoard, 6, 6, 3);
	addInitialValue(boardd, ninjaBoard, 6, 8, 4);
	addInitialValue(boardd, ninjaBoard, 7, 2, 1);
	addInitialValue(boardd, ninjaBoard, 8, 3, 6);
	addInitialValue(boardd, ninjaBoard, 7, 3, 9);
	addInitialValue(boardd, ninjaBoard, 7, 5, 3);
	addInitialValue(boardd, ninjaBoard, 7, 8, 2);
	addInitialValue(boardd, ninjaBoard, 8, 6, 8);
	addInitialValue(boardd, ninjaBoard, 8, 7, 1);

    	addInitialValue(boardd, ninjaBoard, 3, 2, 5);
    	addInitialValue(boardd, ninjaBoard, 3, 3, 2);
    	addInitialValue(boardd, ninjaBoard, 3, 5, 1);
    	addInitialValue(boardd, ninjaBoard, 3, 8, 7);
    	addInitialValue(boardd, ninjaBoard, 4, 0, 7);
    	addInitialValue(boardd, ninjaBoard, 4, 3, 8);

    	addInitialValue(boardd, ninjaBoard, 4, 4, 9);
    	addInitialValue(boardd, ninjaBoard, 5, 0, 2);
    	addInitialValue(boardd, ninjaBoard, 5, 2, 9);
    	addInitialValue(boardd, ninjaBoard, 5, 5, 7);
    	addInitialValue(boardd, ninjaBoard, 5, 6, 5);
    	addInitialValue(boardd, ninjaBoard, 5, 8, 3);

    	addInitialValue(boardd, ninjaBoard, 6, 1, 2);
    	addInitialValue(boardd, ninjaBoard, 6, 3, 1);
    	addInitialValue(boardd, ninjaBoard, 6, 7, 5);
    	addInitialValue(boardd, ninjaBoard, 7, 0, 8);
    	addInitialValue(boardd, ninjaBoard, 7, 1, 5);
    	addInitialValue(boardd, ninjaBoard, 7, 4, 4);

    	addInitialValue(boardd, ninjaBoard, 7, 6, 7);
    	addInitialValue(boardd, ninjaBoard, 7, 7, 6);
    	addInitialValue(boardd, ninjaBoard, 8, 0, 4);
    	addInitialValue(boardd, ninjaBoard, 8, 1, 7);
    	addInitialValue(boardd, ninjaBoard, 8, 2, 3);
    	addInitialValue(boardd, ninjaBoard, 8, 4, 5);

    	addInitialValue(boardd, ninjaBoard, 8, 5, 2);
    	addInitialValue(boardd, ninjaBoard, 8, 8, 9);
}
int main() {

	int keepgoing = 1;
	int restart;
	int board[9][9], ninjaBoard[9][9];
	bool exit = true;
	int option;

	printf("\n");
	
	printf("===============================\n"
		   ">> HELLO! WELCOME TO SUDOKU! <<\n"
	       "===============================\n");
	
	printf("\n");

	printf("Your instructions are as follows:\n"
		"\n"
		"1 - Each block (3X3) must have the numbers 1-9.\n"
		"2 - Each row and column must also have the numbers 1-9.\n"
		"3 - the numbers 1-9 in any block (3x3) or any row or column must not be repeated.\n"
		"\n"
		"Begin playing and have fun!\n");

	while(keepgoing == 1){
		printf("\n");
		printf("What would you like to do?(1-4):\n"
			"1 - Solve the same sudoku game and master it\n"
			"2 - Solve a randomized sudoku game and get a new experiance every time\n"
			"3 - View the games directions again\n"
			"4 - Quit\noption:");
		scanf("%d", &option);
		switch(option){
			case 1:
				exit = true;
				start(board, ninjaBoard);
				createSudokuPuzzle(board, ninjaBoard);
				//display(board);
				while(isFull(ninjaBoard)==false && exit){
					display(board);
					printf("Enter a row:\n");
					int row;
					scanf("%d", &row);
					while(row < 0 || row > 8){
						printf("Please enter a correct row(0-8):\n");
						scanf("%d", &row); 
					} 
					printf("Enter a column: \n");
					int col;
					scanf("%d", &col);
					while(col < 0 || col > 8){
                                                printf("Please enter a correct column(0-8):\n");
                                                scanf("%d", &col); 
                                        } 
					int * allowedvalues;
					allowedvalues = (int *)getAllowedValues(board, row, col);
					printf("\nHere are suggested values: ");
					if(allowedvalues[9] != 0){
						displaySingleArray(allowedvalues, allowedvalues[9]); 
						printf("\nEnter one of the suggested values above or change the value in the cell:");
						int value;
						scanf("%d", &value);
						while(value > 9 && value < 1){
							printf("\nEnter a correct value this time: \n");
							displaySingleArray(allowedvalues, allowedvalues[9]);
							scanf("%d", &value);

						}
						
						addGuess(board, ninjaBoard, row, col, value);
						printf("If you would like to exit, enter 1; if you would like to reset the board, enter -1; enter 0 to continue:");
						int e;
						scanf("%d", &e);
						if(e == 1)
							exit = false;
						else if(e == -1){
							reset(board,ninjaBoard);
							createSudokuPuzzle(board, ninjaBoard);
						}
						printf("\n");
					}
				}
				display(board);
				modifiedCheckPuzzle(board,ninjaBoard)? printf("The board was correctly solved!\n") : printf("The board was not correctly solved.\n");
				/*
				int correct[9][9];
				createCorrectPuzzle(correct, ninjaBoard);
				int sumBoard = 0, sumCorrect = 0;
				for(int j = 0; j < 9; j++){
                                        for(int i = 0; i < 9; i++)
						sumBoard += board[i][j];
				}
				for(int j = 0; j < 9; j++){
                                        for(int i = 0; i < 9; i++)
						sumCorrect += correct[i][j];
				}
				sumBoard == sumCorrect? printf("The board was correctly solved!\n") : printf("The board was not correctly solved.\n");
				
				bool cor=true;
				for(int j = 0; j < 9; j++){
					for(int i = 0; i < 9; i++){
						if(board[i][j] != correct[i][j]){
							cor=false;
							break;
						}
					}
				}
				cor == false? printf("The board was not correctly solved\n"):printf("The board was correctly solved!\n");*/
				reset(board, ninjaBoard);
				break;

			case 2:
				exit = true;
				start(board, ninjaBoard);
				randomizedSudokuPuzzle(board, ninjaBoard);
				while(!isFull(ninjaBoard) && exit){
					display(board);
					printf("Enter a row:\n");
					int row;
					scanf("%d", &row);
					while(row < 0 || row > 8){
                                                printf("Please enter a correct row(0-8):\n");
                                                scanf("%d", &row);
                                        } 
					printf("Enter a column: \n");
					int col;
					scanf("%d", &col);
					while(col < 0 || col > 8){
                                                printf("Please enter a correct column(0-8):\n");
                                                scanf("%d", &col);
                                        } 
					int * allowedvalues;
					allowedvalues = (int *)getAllowedValues(board, row, col);
					printf("\nHere are suggested values: ");
					if(allowedvalues[9] != 0){
						displaySingleArray(allowedvalues, allowedvalues[9]); 
						printf("\nEnter one of the suggested values above or change the value in the cell:");
						int value;
						scanf("%d", &value);
						while(value > 9 && value < 1){
							printf("\nEnter a correct value this time: \n");
							displaySingleArray(allowedvalues, allowedvalues[9]);
							scanf("%d", &value);

						}
						
						addGuess(board, ninjaBoard, row, col, value);
						printf("If you would like to exit enter 1 or 0 to continue:");
						int e;
						scanf("%d", &e);
						if(e == 1)
							exit = false;
						printf("\n");
					}
				}
				if(modifiedCheckPuzzle(board, ninjaBoard))
                                        printf("The board was correctly solved!\n");
                                else
                                        printf("The board was not correctly solved\n");
				reset(board, ninjaBoard);
				break;

			case 3: 
				directions();
				break;

			case 4:
				keepgoing = 0;
				break;

		}
	}
}
