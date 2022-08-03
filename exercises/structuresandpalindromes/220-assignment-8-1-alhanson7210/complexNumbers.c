//libraries
#include <stdio.h>
#include <stdlib.h>
//structures
struct Complex{
        float real, imaginary;
};
//prototypes
void display(struct Complex *number);
struct Complex * add(struct Complex *firstNumber, struct Complex *secondNumber);
struct Complex * subtract(struct Complex *firstNumber, struct Complex *secondNumber);
//driver
int main(void){
	int userChoice = 0, first = 0, second = 0;
	struct Complex *firstNum = malloc(sizeof(struct Complex)), *secondNum = malloc(sizeof(struct Complex)), *currentNumber = malloc(sizeof(struct Complex));
	printf("\nMENU DRIVEN COMPLEX NUMBER OPERATIONS\n");
	while(userChoice != 3){
		printf("\nCOMPLEX NUMBERS\n1.Add two complex numbers\n2.Subtract two complex numbers\n3.Exit the program\nEnter an option: ");
		scanf("%d", &userChoice);
		while (userChoice < 1 || userChoice > 3) {
			printf("\nEnter a valid option: ");
			scanf("%d", &userChoice);
		}
		switch(userChoice){
			case 1:
				//first complex number
				printf("\nEnter a and b as in ai + b for the first complex number.\na = ");
				scanf("%d", &first);
				firstNum -> imaginary = (float) first;

				printf("\nb = ");
				scanf("%d", &second);
				firstNum -> real = (float) second;

				//second complex number
				printf("\nEnter c and d as in ci + d for the first complex number.\nc = ");
                                scanf("%d", &first);
                                secondNum -> imaginary = (float) first;
                                
				printf("\nd = ");
                                scanf("%d", &second);
                                secondNum -> real = (float) second;

				//add the first and second complex numbers
				currentNumber = add(firstNum, secondNum);
				
				//display the result
				display(currentNumber);
				break;
			case 2:
				//first complex number
                                printf("\nEnter a and b as in ai + b for the first complex number.\na = ");
                                scanf("%d", &first);
				firstNum -> imaginary = (float) first;

                                printf("\nb = ");
                                scanf("%d", &second);
				firstNum -> real = (float) second;

                                //second complex number
                                printf("\nEnter c and d as in ci + d for the second complex number.\nc = ");
                                scanf("%d", &first);
				secondNum -> imaginary = (float) first;
                                
				printf("\nd = ");
                                scanf("%d", &second);
				secondNum -> real = (float) second;

				//subtract the first and second complex numbers
				currentNumber = subtract(firstNum, secondNum);

				//display the result
				display(currentNumber);
				break;
			case 3:
				userChoice = 3;
				break;
			default:
				userChoice = 3;
				break;
		}
	}
	
	return 0;
}
//functions definitions
//display a complex number
void display(struct Complex *number){
	printf("\nThe complex number is %.1fi + %.1f.\n", number -> imaginary, number -> real);
}
//adding two complex numbers
struct Complex * add(struct Complex *firstNumber, struct Complex *secondNumber){
	struct Complex *result = malloc(sizeof(struct Complex));
	result -> imaginary = (firstNumber -> imaginary) + (secondNumber -> imaginary);
	result -> real = (firstNumber -> real) + (secondNumber -> real);
	return result;
}
//subtracting two complext numbers
struct Complex * subtract(struct Complex *firstNumber, struct Complex *secondNumber){
	struct Complex *result = malloc(sizeof(struct Complex));
	result -> imaginary = (firstNumber -> imaginary) - (secondNumber -> imaginary);
        result -> real = (firstNumber -> real) - (secondNumber -> real);
        return result;
}
//End of the program code
