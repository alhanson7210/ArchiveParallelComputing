#include<stdio.h>
void input(int arr[], int n) {
        for(int i = 0; i < n; i++)
                scanf("%d", &arr[i]);
}
void display(int arr[], int n) {
        for(int i = 0; i < n; i++) {
                printf("arr[%d] is %d.\n", i, arr[i]);
        }
}

void bubbleSort(int arr[], int size){
	for(int pos = 0; pos < size; pos++){
		int temp;
		for(int j = size-1; j > pos; j--){
			if(arr[j] > arr[j-1]){
				temp = arr[j-1];
				arr[j-1] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

int linearSearch(int arr[], int n, int element) {
        int idx = -1;
        for(int i = 0; i < n; i++) {
                if(arr[i] == element)
                        return i;
        }
        return idx;
}

//make sure to shift the elements to to left after finding the element
void deleteElement(int arr[], int n, int element) {
        for(int i = 0; i < n; i++) {
                if(arr[i] == element){
			for(int j = i; j < n; j++){
				arr[j] = arr[j+1];
			}
			return;
		}
        }
}

//leave space for insertions into the array
void insertElement(int arr[], int idx, int element, int size){
	if(idx >= size || idx < 0)
		return;
	for(int i = size-1; i >= idx; i--){
		arr[i+1] = arr[i];
	}
	arr[idx] = element;	
}

int main(){
	int n,option = 0, searchElement, oldElement,newElement,deletedElement,lnrsch,maxSize;
        printf("\nEnter the number of elements:");
        scanf("%d", &n);
        int arr[n*n];
	input(arr,n);
	maxSize=n*n;
	while(option != 6){
		printf("\nPlease enter a menu option from 1-6 where:\n1.To use bubble sort on the array\n2.To use linear search to find an element in the array\n3.Insert an element at a certain index\n4.Delete an element in the array\n5.Display the array\n6.Exit\nOption:");
		scanf("%d", &option);
		while(option < 1 || option > 6){
			printf("\nPlease enter a menu option from 1-6:");
			scanf("%d", &option);
		}
		switch(option){
			case 1:
				bubbleSort(arr,n);
				break;
			case 2:
				printf("\nEnter an element/number you want to look for in the array:");
				scanf("%d", &searchElement);
				lnrsch = linearSearch(arr,n,searchElement);
				lnrsch == -1? printf("%d element is not present", searchElement):printf("%d is present in the array",searchElement);
				break;
			case 3:
				if(n == maxSize){
					printf("You have reached the limit of elements that can be added to the array. Max size is %d",maxSize);
					break;
				}
				if(n == 0){
                                        printf("No more elements in the array!");
                                        break;
                                }
				printf("\nEnter an element to insert:");
				scanf("%d", &newElement);
				printf("\nEnter the index to insert it in at:");
				scanf("%d", &oldElement);
				if(linearSearch(arr,n,arr[oldElement]) == -1){
					break;
				} else {
					insertElement(arr,oldElement,newElement,n);
					n++;
				} 
				break;
			case 4:
				if(n == 0){
					printf("No more elements in the array!");
					break;
				}
				printf("\nEnter an element/number you want to delete from in the array:");
				scanf("%d", &deletedElement);
				if(linearSearch(arr,n,deletedElement) == -1){
					break;
				} else {
					deleteElement(arr,n,deletedElement);
                                	n--;
				}
				break;
			case 5:
				display(arr,n);
				break;
			default:
				break;

		}
	}
	return 0;
}
