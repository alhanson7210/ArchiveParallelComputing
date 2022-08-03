#include<stdio.h>
void input(int array[], int length) {
	for(int idx = 0; idx < length; idx++) {
		printf("\nArray element %d:", idx+1);
		scanf("%d", &array[idx]);
	}
}

void display(int array[], int length) {
	for(int idx = 0; idx < length; idx++) {
		printf("Array[%d] is %d.\t", idx, array[idx]);	
	}
	printf("\n");
}

void rshift(int array[], int length) {
	int temp = array[length-1];
	for(int idx = length-2; idx >= 0; idx--) {
		array[idx+1] = array[idx]; 
	}
	array[0] = temp;
}

void lshift(int array[], int length) {
        int temp = array[0];
        for(int idx = 1; idx < length; idx++) {
                array[idx-1] = array[idx];
        }
        array[length-1] = temp;
}

void circularShift(int array[], int length, int shifts) {
	//base case being 0
	if(shifts == 0){
		return;
	}
	//adding to the shift when recursively calling circular shift for negative inputs of element shifts 
	else if(shifts < 0){
		lshift(array,length);
		circularShift(array,length,shifts+1);
	}
	//subtracting the shift when recursively calling circular shift for negative inputs of element shifts 
	else {
		rshift(array,length);
		circularShift(array,length, shifts-1);
	}
}

int main() {
	int arrayLength, shifts;
	printf("\nEnter the number of elements in the array:");
	scanf("%d", &arrayLength);
	int array[arrayLength];
	input(array, arrayLength);
	printf("\nEnter the amount of circular shifts:");
        scanf("%d", &shifts);
	printf("\nOriginal array:");
	display(array,arrayLength);
	shifts %= arrayLength;
	circularShift(array,arrayLength,shifts);
	printf("Shifted Array:");
	display(array,arrayLength);
}
