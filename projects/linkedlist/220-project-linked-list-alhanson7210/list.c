/*libraries*/
#include <stdio.h>
#include <stdlib.h>

/*structures*/
struct Node {
	int data;
	struct Node *next;
};

/*prototypes*/
void concat(struct Node *head);
int min(struct Node *head);
int max(struct Node *head);
struct Node * reverse(struct Node *head);
struct Node * sort(struct Node *head);
/*driver*/
int main(void) {
	struct Node *head = NULL;
	
}

/*functions*/
//
void concat(struct Node *head) {
	if(head == NULL) {
		printf("\nNULL");
		return;
	}

	if(head -> next == NULL){
		printf("\n%d -> NULL", head -> data);
		return;
	}

	struct Node * currentNode = head;
	printf("\n%d -> ", currentNode -> data);
	while(currentNode -> next != NULL) {
		printf("%d -> ", (currentNode -> next) -> data));
		currentNode = currentNode -> next;
	}
	printf(" NULL");
//output should be: NULL or d -> NULL or d -> d -> d -> NULL
}
//
int min(struct Node *head) {
	if(head == NULL)
                return 0;

	if(head -> next == NULL)
		return head -> data;

	int min = head -> data;
	struct Node *currentNode = head;
	while(currentNode -> next != NULL) {
		if (min  > ((currentNode -> next) -> data))
			min = (currentNode -> next) -> data);
		currentNode = currentNode -> next;
	}

	return min;
}
//
int max(struct Node *head) {
	if(head == NULL)
                return 0;

	if(head -> next == NULL)
                return head -> data;

	int max = head -> data;
        struct Node *currentNode = head;
	while(currentNode -> next != NULL) {
                if (max < ((currentNode -> next) -> data))
                        max = (currentNode -> next) -> data);
		currentNode = currentNode -> next;
        }

	return max;

}
//
struct Node * reverse(struct Node *head) {
	if(head == NULL || (head -> next) == NULL)
                return head;
	
	struct Node *reversedList = head;
	struct Node *currentNode = head;
	reversedList -> next = NULL;
	struct Node *temp = NULL;

	while(currentNode -> next != NULL) {
		temp = currentNode -> next;
		temp -> next = reversedList;
		reversedList = temp;
		currentNode = currentNode -> next;
	}

	return reversedList;
}
struct Node * middleNode(struct Node *head){

}
struct Node * merge(struct Node *leftside, struct Node *rightside) {

}
//
struct Node * sort(struct Node *head) {
        if(head == NULL || (head -> next) == NULL)
                return head;
	struct node *MiddleNode = middleNode(head);
	struct node *nextAfterMiddle = MiddleNode -> next;
	MiddleNode -> next = NULL;
	struct node *leftside = sort(head);
	struct Node *rightside = sort(nextAfterMiddle);
	return merge(leftside, rightside);
}
//END OF THE PROGRAM
//ION - architypes of the collective unconscious 
