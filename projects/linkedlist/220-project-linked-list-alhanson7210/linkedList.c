/*
 * Serial Program
 */

/*
 *libraries
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*
 *enumerations
 */
enum dataType {CHAR = 1,FLOAT,LIST,INT,STRING};

/*
 *Constants
 */
char * types[] = {"CHAR", "FLOAT", "LIST", "INT", "STRING"};

/*
 *stuctures
 */
struct Node {
	union {
		char c;
		float f;
		struct Node *l;
		int n;
		char * s;
	};
	enum dataType type;
	struct Node *next;
};

/*
 *prototypes
 */
void print(struct Node * list);
struct Node * append(struct Node * list, struct Node * listItem);
struct Node * insert(struct Node * list, int index, struct Node * value);
struct Node * del(struct Node * list, struct Node * listElement);
struct Node * concat(struct Node * list1, struct Node * list2);
struct Node * reverse(struct Node * list);
struct Node * createList(void);
struct Node * createElement(void);
struct Node * binsort(struct Node * list);
int length(struct Node * list);
int min(struct Node * list);
int max(struct Node * list);

/*
 *driver
 */
int main(void) {
	//initializers
	int option = 0, listNumber, Max, Min, index, value, newNodeType, delNodeType, i, flh, slh;
        char str;
        char *string = malloc(100 * sizeof(char));
	struct Node *firstListHead = NULL, *secondListHead = NULL, *concatedList = NULL, *newNode = NULL, *delNode = NULL, *appendedElement, *reversedList = NULL, *temp = NULL;

	//create two lists to start with
	printf("\nFor the first list:");
	firstListHead = createList();
	printf("\nFor the second list:");
	secondListHead =  createList();

	//menu drive list
	printf("\nPYTHON-LIKE LIST FUNCTIONALITY FROM A LINKED LIST");

	//loop for the menu
	bool Continue = true;
	while (Continue) {
		printf("\n1.append\n2.concat\n3.delete\n4.insert\n5.max\n6.min\n7.print\n8.reverse\n9.exit\noption:");
		scanf("%d", &option);
		switch (option) {
			case 1:
				printf("\n1. first list\n2. second list\n3. exit\noption:");
				scanf("%d", &listNumber);
				while (listNumber < 1 || listNumber > 3) {
                                	printf("\n1. first list\n2. second list\n3. exit");
                                	scanf("%d", &listNumber);
				}
				switch(listNumber) {
					case 1:
						appendedElement = createElement();
						firstListHead = append(firstListHead, appendedElement);
						print(firstListHead);
						break;
                                        case 2:
                                                appendedElement = createElement();             
                                                secondListHead = append(secondListHead, appendedElement);
                                                print(secondListHead);
                                                break;
                                        default:
                                                break;
				}
				break;
                        case 2:
				flh = length(firstListHead), slh = length(secondListHead);
				concatedList = concat(firstListHead,secondListHead);
				printf("\nThe combined list is:");
				print(concatedList);
                                secondListHead = NULL;
				for(i = 0; i < slh; i++){
					temp = concatedList;
					concatedList = concatedList -> next;
					temp -> next = NULL;
                                        secondListHead = append(secondListHead, temp);
				}
                                firstListHead = NULL;
				for(i = 0; i < flh; i++){
                                        temp = concatedList;
                                        concatedList = concatedList -> next;
                                        temp -> next = NULL;
                                        firstListHead = append(firstListHead,temp);
				}
				printf("\n%d list elements combined has been undone.", i+slh);
                                break;
                        case 3:
                                printf("\n1. first list\n2. second list\n3. exit\noption:");
                                scanf("%d", &listNumber);
                                while (listNumber < 1 || listNumber > 3) {
                                        printf("\n1. first list\n2. second list\n3. exit\noption:");
                                        scanf("%d", &listNumber);
                                }
                                switch(listNumber) {
                                        case 1:
						delNode = malloc(sizeof(struct Node));
						printf("\nWhat data type would this deleted element be\n1. CHAR\n2. FLOAT\n3. LIST\n4. INT\n5. STRING\nOption: ");
                                                scanf("%d", &delNodeType);
                                                while(delNodeType < 1 || delNodeType > 5) {
                                                        printf("\nInvalid Option!\nWhat data type would this element be\n1. CHAR\n2. FLOAT\n3. LIST\n4. INT\n5. STRING\nOption: ");
                                                        scanf("%d", &delNodeType);
                                                }
						switch(delNodeType) {
							case 1: 
								delNode -> type = CHAR;
								break;
                                                        case 2: 
                                                                delNode -> type = FLOAT;
                                                                break;
                                                        case 3: 
                                                                delNode -> type = LIST;
                                                                break;
                                                        case 4: 
                                                                delNode -> type = INT;
                                                                break;
                                                        case 5: 
                                                                delNode -> type = STRING;
                                                                break;
                                                        default: 
                                                                break;
						}
                                                printf("\nEnter a(n) %s element:", types[delNodeType - 1]);
                                                switch(delNode -> type) {
                                                        case CHAR:
                                                                scanf("%c", &delNode -> c);
								scanf("%c", &delNode -> c);
                                                                break;

                                                        case FLOAT:
                                                                scanf("%f", &delNode -> f);
                                                                break;

                                                        case LIST:
                                                                delNode -> l = createList();
                                                                break;

                                                        case INT:
                                                                scanf("%d", &delNode -> n);
                                                                break;

                                                        case STRING:
                                                                scanf("%c", &str);
                                                                scanf("%s", string);
                                                                delNode -> s = string;
                                                                break;

                                                        default:
								break;
						}
						firstListHead = del(firstListHead, delNode);
						print(firstListHead);
						//free(delNode);
                                                break;
                                        case 2:
                                                delNode = malloc(sizeof(struct Node));
                                                printf("\nWhat data type would this deleted element be\n1. CHAR\n2. FLOAT\n3. LIST\n4. INT\n5. STRING\nOption: ");
                                                scanf("%d", &delNodeType);
						fflush(stdin);
                                                while(delNodeType < 1 || delNodeType > 5) {
                                                        printf("\nInvalid Option!\nWhat data type would this element be\n1. CHAR\n2. FLOAT\n3. LIST\n4. INT\n5. STRING\nOption: ");
                                                        scanf("%d", &delNodeType);
							fflush(stdin);
                                                }
                                                switch(delNodeType) {
                                                        case 1:
                                                                delNode -> type = CHAR;
                                                                break;
                                                        case 2:
                                                                delNode -> type = FLOAT;
                                                                break;
                                                        case 3:
                                                                delNode -> type = LIST;
                                                                break;
                                                        case 4:
                                                                delNode -> type = INT;
                                                                break;
                                                        case 5:
                                                                delNode -> type = STRING;
                                                                break;
                                                        default:
                                                                break;
                                                }
                                                printf("\nEnter a(n) %s element:", types[delNodeType - 1]);
                                                switch(delNode -> type) {
                                                        case CHAR:
                                                                scanf("%c", &delNode -> c);
								scanf("%c", &delNode -> c);
                                                                break;

                                                        case FLOAT:
                                                                scanf("%f", &delNode -> f);
                                                                break;

                                                        case LIST:
                                                                delNode -> l = createList();
                                                                break;

                                                        case INT:
                                                                scanf("%d", &delNode -> n);
                                                                break;

                                                        case STRING:
                                                                scanf("%c", &str);
                                                                scanf("%s", string);
                                                                delNode -> s = string;
                                                                break;

                                                        default:
                                                                break;
                                                }
						fflush(stdin);
                                                secondListHead = del(secondListHead, delNode);
                                                print(secondListHead);
                                                //free(delNode);
                                                break;
                                        default:
                                                break;
                                }
                                break;
                        case 4:
                                printf("\n1. first list\n2. second list\n3. exit\noption:");
                                scanf("%d", &listNumber);
                                while (listNumber < 1 || listNumber > 3) {
                                        printf("\n1. first list\n2. second list\n3. exit\noption:");
                                        scanf("%d", &listNumber);
                                }
                                switch(listNumber) {
                                        case 1:
						newNode = malloc(sizeof(struct Node));
						printf("\nEnter the index of where the element is to be placed: ");
						scanf("%d", &index);
						printf("\nWhat data type would this element be\n1. CHAR\n2. FLOAT\n3. LIST\n4. INT\n5. STRING\nOption: ");
						scanf("%d", &newNodeType);
						while(newNodeType < 1 || newNodeType > 5) {
                					printf("\nInvalid Option!\nWhat data type would this element be\n1. CHAR\n2. FLOAT\n3. LIST\n4. INT\n5. STRING\nOption: ");
                					scanf("%d", &newNodeType);
        					}
                                                switch(newNodeType) {
                                                        case 1:
                                                                newNode -> type = CHAR;
                                                                break;
                                                        case 2:
                                                                newNode -> type = FLOAT;
                                                                break;
                                                        case 3:
                                                                newNode -> type = LIST;
                                                                break;
                                                        case 4:
                                                                newNode -> type = INT;
                                                                break;
                                                        case 5:
                                                                newNode -> type = STRING;
                                                                break;
                                                        default:
                                                                break;
                                                }
						printf("\nEnter a(n) %s element:", types[newNodeType - 1]);
						switch(newNode -> type) {
                					case CHAR:
                        					scanf("%c", &newNode -> c);
								scanf("%c", &newNode -> c);
                        					break;

                					case FLOAT:
                        					scanf("%f", &newNode -> f);
                        					break;

                					case LIST:
                        					newNode -> l = createList();
                        					break;

                					case INT:
                        					scanf("%d", &newNode -> n);
                        					break;

                					case STRING:
                                                                scanf("%c", &str);
                                                                scanf("%s", string);
                                                                newNode -> s = string;
                        					break;

					                default:
                        					break;
						}
						firstListHead = insert(firstListHead, index, newNode);
						print(firstListHead);
						//free(newNode);
                                                break;
                                        case 2:
                                                newNode = malloc(sizeof(struct Node));
                                                printf("\nEnter the index of where the element is to be placed: ");
                                                scanf("%d", &index);
                                                printf("\nWhat data type would this element be\n1. CHAR\n2. FLOAT\n3. LIST\n4. INT\n5. STRING\nOption: ");
                                                scanf("%d", &newNodeType);
                                                while(newNodeType < 1 || newNodeType > 5) {
                                                        printf("\nInvalid Option!\nWhat data type would this element be\n1. CHAR\n2. FLOAT\n3. LIST\n4. INT\n5. STRING\nOption: ");
                                                        scanf("%d", &newNodeType);
                                                }
                                                switch(newNodeType) {
                                                        case 1:
                                                                newNode -> type = CHAR;
                                                                break;
                                                        case 2:
                                                                newNode -> type = FLOAT;
                                                                break;
                                                        case 3:
                                                                newNode -> type = LIST;
                                                                break;
                                                        case 4:
                                                                newNode -> type = INT;
                                                                break;
                                                        case 5:
                                                                newNode -> type = STRING;
                                                                break;
                                                        default:
                                                                break;
                                                }
                                                printf("\nEnter a(n) %s element:", types[newNodeType - 1]);
                                                switch(newNode -> type) {
                                                        case CHAR:
                                                                scanf("%c", &newNode -> c);
								scanf("%c", &newNode -> c);
                                                                break;

                                                        case FLOAT:
                                                                scanf("%f", &newNode -> f);
                                                                break;

                                                        case LIST:
                                                                newNode -> l = createList();
                                                                break;

                                                        case INT:
                                                                scanf("%d", &newNode -> n);
                                                                break;

                                                        case STRING:
                        					scanf("%c", &str);
                        					scanf("%s", string);
                        					newNode -> s = string;
                                                                break;

                                                        default:
                                                                break;
                                                }
                                                secondListHead = insert(secondListHead, index, newNode);
						print(secondListHead);
						//free(newNode);
                                                break;
                                        default:
                                                break;
				
                                }
                                break;
                        case 5:
                                printf("\n1. first list\n2. second list\n3. exit\noption:");
                                scanf("%d", &listNumber);
                                while (listNumber < 1 || listNumber > 3) {
                                        printf("\n1. first list\n2. second list\n3. exit\noption:");
                                        scanf("%d", &listNumber);
                                }
                                switch(listNumber) {
                                        case 1:
						Max = max(firstListHead);
                                                printf("\nThe maximum value in the list is %d", Max);
                                                break;
                                        case 2:
						Max = max(secondListHead);
                                                printf("\nThe maximum value in the list is %d", Max);
                                                break;
                                        default:
                                                break;
                                }
                                break;
                        case 6:
                                printf("\n1. first list\n2. second list\n3. exit\noption:");
                                scanf("%d", &listNumber);
                                while (listNumber < 1 || listNumber > 3) {
                                        printf("\n1. first list\n2. second list\n3. exit\noption:");
                                        scanf("%d", &listNumber);
                                }
                                switch(listNumber) {
                                        case 1:
						Min = min(firstListHead);
						printf("\nThe minimum value in the list is %d", Min);
                                                break;
                                        case 2:
						Min = min(secondListHead);
                                                printf("\nThe minimum value in the list is %d", Min);
                                                break;
                                        default:
                                                break;
                                }
                                break;
                        case 7:
                                printf("\n1. first list\n2. second list\n3. exit\noption:");
                                scanf("%d", &listNumber);
                                while (listNumber < 1 || listNumber > 3) {
                                        printf("\n1. first list\n2. second list\n3. exit\noption:");
                                        scanf("%d", &listNumber);
                                }
                                switch(listNumber) {
                                        case 1:
						print(firstListHead);
                                                break;
                                        case 2:
						print(secondListHead);
                                                break;
                                        default:
                                                break;
                                }
                                break;
                        case 8:
                                printf("\n1. first list\n2. second list\n3. exit\noption:");
                                scanf("%d", &listNumber);
                                while (listNumber < 1 || listNumber > 3) {
                                        printf("\n1. first list\n2. second list\n3. exit\noption:");
                                        scanf("%d", &listNumber);
                                }
                                switch(listNumber) {
                                        case 1:
						firstListHead = reverse(firstListHead);
						printf("\nFirst List Reversed: ");
						print(firstListHead);
                                                break;
                                        case 2:
						secondListHead = reverse(secondListHead);
                                                printf("\nSecond List Reversed: ");
                                                print(secondListHead);
                                                break;
                                        default:
                                                break;
                                }
                                break;
                        default:
				Continue = false;
                                break;
		}	
	}
        /*free(firstListHead);
	free(secondListHead); 
	free(concatedList); 
	free(newNode); 
	free(delNode);
	free(appendedElement);*/
	return 0;
}

/*
 * Declarations
 */

/*
 *Create a list element
 */
struct Node * createElement(void) {
	int option = 0;
	char str;
	char *string = malloc(100 * sizeof(char));
	struct Node *temp = malloc(sizeof(struct Node));
	printf("\nWhat data type would this element be\n1. CHAR\n2. FLOAT\n3. LIST\n4. INT\n5. STRING\nOption: ");
        scanf("%d", &option);
        while(option < 1 || option > 5) {
        	printf("\nInvalid Option!\nWhat data type would this element be\n1. CHAR\n2. FLOAT\n3. LIST\n4. INT\n5. STRING\nOption: ");
        	scanf("%d", &option);
        }
        switch(option) {
        	case 1:
                	temp -> type = CHAR;
                      	break;
        	case 2:
                        temp -> type = FLOAT;
                        break;
                case 3:
                        temp -> type = LIST;
                        break;
                case 4:
                        temp -> type = INT;
                        break;
                case 5:
                        temp -> type = STRING;
                        break;
        	default:
                	break;
        }
        printf("\nEnter the element: ");
        switch(temp -> type) {
        	case CHAR:
                	scanf("%c", &temp -> c);
			scanf("%c", &temp -> c);
                        break;

                case FLOAT:
                        scanf("%f", &temp -> f);
                        break;

                case LIST:
                        temp -> l = createList();
                        break;

                case INT:
                        scanf("%d", &temp -> n);
                        break;

                case STRING:
                        scanf("%c", &str);
                        scanf("%s", string);
                        temp -> s = string;
                        break;

                default:
                        break;
	}
	//free(string);
	temp -> next = NULL;
	return temp;
}
/*
 *Creates a list of elements(linked list)
 */
struct Node * createList(void) {
	//initializations
	int i, ln, option;
	char str;
	char * string = malloc(sizeof(char) * 100);
	struct Node *temp = NULL, *list = NULL;

	//validation
	printf("\nEnter the number of elements in the list: ");
	scanf("%d", &ln);
	while(ln < 1) {
	        printf("\nNon-negative numbers only please. Please enter the number of elements in the list: ");
        	scanf("%d", &ln);
	}

	//create list of elements
	for (i = 0; i < ln; i++) {
		//new list element
		printf("\nThere are %d out of %d needed to finish the list.", i+1, ln);
		temp = malloc(sizeof(struct Node));

		//character validation
		printf("\nWhat data type would this element be\n1. CHAR\n2. FLOAT\n3. LIST\n4. INT\n5. STRING\nOption: ");
                scanf("%d", &option);
		fflush(stdin);
                while(option < 1 || option > 5) {
                        printf("\nInvalid Option!\nWhat data type would this element be\n1. CHAR\n2. FLOAT\n3. LIST\n4. INT\n5. STRING\nOption: ");
                        scanf("%d", &option);
			fflush(stdin);
                }
        	switch(option) {
                	case 1:
                        	temp -> type = CHAR;
                        	break;
                	case 2:
                        	temp -> type = FLOAT;
                        	break;
                	case 3:
                        	temp -> type = LIST;
                        	break;
                	case 4:
                        	temp -> type = INT;
                        	break;
               		case 5:
                	        temp -> type = STRING;
                	        break;
                	default:
                	        break;
        	}		
		//based off the designated type assign the element
                printf("\nEnter a(n) %s type element: ", types[option-1]);
                switch(temp -> type) {
                        case CHAR:
                                scanf("%c", &temp -> c);
				scanf("%c", &temp -> c);
                                break;

                        case FLOAT:
                                scanf("%f", &temp -> f);
                                break;

                        case LIST:
				//recursively call to have list of lists
                                temp -> l = createList();
                                break;

                        case INT:
                                scanf("%d", &temp -> n);
                                break;

                        case STRING:
                        	scanf("%c", &str);
				scanf("%s", string);
				temp -> s = string;
                                break;

                        default:
                                break;
                }
		fflush(stdin);
		//reassign the head of the list
		temp -> next = list;
		list = temp;
	}
	/*free(temp);
	free(string);*/
	//return finished list
	return list;
}

/*
 * print a given list
 */
void print(struct Node * list) {
	if (list == NULL)
		printf("[]");

	if(list -> next == NULL) {
		switch(list -> type) {
			case CHAR:
				printf("[%c]", list -> c);
				break;
			case FLOAT:
				printf("[%f]", list -> f);
				break;

			case INT:
				printf("[%d]", list -> n);
				break;

			case LIST:
				if(list -> l == NULL) {
					printf("[]");
					break;
				}
				struct Node * currentNode = list -> l;
				printf("[");
				while(currentNode != NULL) {
					switch(currentNode -> type){
						case CHAR:
                                			printf("%c,", list -> c);
                                			break;
                        			case FLOAT:
                                			printf("%f,", list -> f);
                                			break;

                        			case INT:
                                			printf("%d,", list -> n);
                                			break;
						case LIST:
							/*print(currentNode)*/printf("[...]");
							break;
						case STRING:
							printf("'");
                                			char *s = currentNode -> s;
                                			/*int i = 0;
                                			while(*(s+i) != '\0') {
                                        			printf("%c, ", *(s+i));
                                			}*/
							printf("%s", s);
                                			printf("',");
                                			break;
						default:
							break;
					}
					currentNode = currentNode -> next;
				}
				printf("]");
				break;

			case STRING:
				printf("['");
				char *s = list -> s;
				/*int i = 0;
				while(*(s+i) != '\0') {
					printf("%c, ", *(s+i));
				}*/
				printf("%s", s);
				printf("']");
				break;

			default:
				break;
		}
		return;
	}

	struct Node * currentNode = list;
	printf("[");
        while(currentNode -> next != NULL) {
		switch(currentNode -> type) {
			case CHAR:
				printf("%c,",currentNode -> c);
				break;
			case FLOAT:
				printf("%f,",currentNode -> f);
				break;
			case INT:
				printf("%d,",currentNode -> n);
				break;
			case LIST:
				/*print(currentNode)*/printf("[...],");
				break;
			case STRING:
				printf("'");
                                char *s = currentNode -> s;
                                /*int i = 0;
                                while(*(s+i) != '\0') {
                                	printf("%c,", *(s+i));
                                }*/
				printf("%s", s);
                                printf("',");
				break;
			default:
				break;
		}
		currentNode = currentNode -> next;
	}
	switch(currentNode -> type) {
        	case CHAR:
                	printf("%c",currentNode -> c);
                        break;
                case FLOAT:
                        printf("%f",currentNode -> f);
                        break;
                case INT:
                        printf("%d",currentNode -> n);
                        break;
                case LIST:
                        /*print(currentNode)*/printf("[...]");
                        break;
                case STRING:
                        printf("'");
                        char *s = currentNode -> s;
                        /*int i = 0;
                        while(*(s+i) != '\0') {
                        	printf("%c,", *(s+i));
                        }*/
                        printf("%s", s);
                        printf("'");
                        break;
                default:
                        break;
        }
	printf("]");
}

/*
 *
 */
struct Node * append(struct Node* list, struct Node* listItem) {
	if((list == NULL && listItem == NULL) || (list != NULL && listItem == NULL))
		return list;

	if(list == NULL && listItem != NULL)
		return listItem;

	struct Node * currentNode = list;
	while(currentNode -> next != NULL) {
		currentNode = currentNode -> next;
	}
	currentNode -> next = listItem;
	return list;
}

/*
 * insert
 */
struct Node * insert(struct Node* list, int index, struct Node* value) {
	if(list == NULL)
		return value;

	if(index < 0)
		return list;

	if(index == 0) {
		value -> next = list;
		return value;
	}
	
	if(index > length(list)) {
		return append(list,value);
	}

	int i = 0;
	struct Node * currentnode = list;
	while (i != index && currentnode != NULL) {
		if (i == index-1) {
			value -> next = currentnode -> next;
			currentnode -> next = value;
			return list;
		}
		i++;
		currentnode = currentnode -> next;
	}
	return list;
}

/*
 * del element from a list
 */
struct Node * del(struct Node* list, struct Node* listElement) {
	if(list == NULL)
		return list;
	//ONLY ONE ELEMENT IN THE LIST
	if(listElement -> type == list -> type && list -> next == NULL) {
		switch(listElement -> type) {
			case CHAR:
				if(listElement -> c == list -> c) {
					return NULL;
				}
                                break;
			case FLOAT:
                                if(listElement -> f == list -> f) {
                                        return NULL;
                                }
                                break;
			case INT:
                                if(listElement -> n == list -> n) {
                                        return NULL;
                                }
                                break;
			case LIST:
                                if(listElement -> l == list -> l) {
					return NULL;
                                }
                                break;
			case STRING:
                                if(strcmp(listElement -> s,list -> s) == 0) {
                                        return NULL;
                                }
				break;
			default:
				break;
		}
		return list;
	}	
	
	//CHECKING THE FIRST ELEMENT IF IT NEEDS TO BE DELETED TO MAKE DELETING EASIER TO CODE
	struct Node * currentnode = list;
	struct Node * temp = list;
	if(listElement -> type == currentnode -> type) {
        	switch(listElement -> type) {
                	case CHAR:
                        	if(listElement -> c == currentnode -> c) {
                                        temp = currentnode -> next;
					free(currentnode);
					return temp;
                                }
                                break;
                        case FLOAT:
                                if(listElement -> f == currentnode -> f) {
					temp = currentnode -> next;
                                        free(currentnode);
					return temp;
                                }
                                break;
                        case INT:
                                if(listElement -> n == currentnode -> n) {
                                        temp = currentnode -> next;
                                        free(currentnode);
                                        return temp; 
                                }
                                break;
                        case LIST:
                                if(listElement -> l == currentnode -> l) {
                                        temp = currentnode -> next;
                                        free(currentnode);
                                        return temp; 
                                }
                                break;
                        case STRING:
                                if(strcmp(listElement -> s,currentnode -> s) == 0) {
                                        temp = currentnode -> next;
                                        free(currentnode);
                                        return temp; 
                                }
                                break;
			default:
				break;
        	}
        }

	free(temp);
	struct Node * NextNode = currentnode -> next;
	//CHECKING ELEMENTS AFTER THE FIRST NODE
	while(currentnode != NULL) {
		if(listElement -> type == NextNode -> type) {
			switch(listElement -> type) {
				case CHAR:
                                	if(listElement -> c == NextNode -> c) {
                                        	currentnode -> next = NextNode -> next;
						free(NextNode);
						return list;
                                	}
                                	break;
                        	case FLOAT:
                                	if(listElement -> f == NextNode -> f) {
                                                currentnode -> next = NextNode -> next;
                                                free(NextNode);
						return list;
                                	}
                                	break;
                        	case INT:
                                	if(listElement -> n == NextNode -> n) {
                                                currentnode -> next = NextNode -> next;
                                                free(NextNode);
                                        	return list;
                                	}
                                	break;
                        	case LIST:
                                	if(listElement -> l == NextNode -> l) {
                                                currentnode -> next = NextNode -> next;
                                                free(NextNode);
                                        	return list;
                                	}
                                	break;
                        	case STRING:
                                	if(strcmp(listElement -> s,NextNode -> s) == 0) {
                                                currentnode -> next = NextNode -> next;
                                                free(NextNode);
                                        	return list;
                                	}
                                	break;
				default:
					break;
			}
		}
		currentnode = NextNode;
		NextNode = NextNode -> next;
	}
	return list;
}

/*
 * combine two lists
 */
struct Node * concat(struct Node* list1, struct Node* list2) {
	struct Node * combinedList = NULL;

	if(list1 == NULL && list2 == NULL)
		return NULL;

	else if(list1 == NULL && list2 != NULL)
		return list2;

	else if(list1 != NULL && list2 == NULL)
		return list1;

	/*else if( ((list1 -> next) == NULL) && ((list2 -> next) == NULL) ) {
		struct Node * list = list1;
		list -> next = list2;
		return list;
	}*/

	struct Node * listOne = list1;
	struct Node * listTwo = list2;
	struct Node * temp = NULL;

	while(listOne != NULL) {
		temp = listOne;
                listOne = listOne -> next;
		temp -> next = combinedList;
		combinedList = temp;
	}

	while(listTwo != NULL) {
                temp = listTwo;
		listTwo = listTwo -> next;
                temp -> next = combinedList;
                combinedList = temp;
        }

	return combinedList;
}

/*
 * reverses the order of the list
 */
struct Node * reverse(struct Node* list) {
	if(list == NULL || (list -> next) == NULL)
                return list;

	//first element
	struct Node *reversedList = NULL;
	
	//create temporary node to re-assign the head of the list
        struct Node *temp = NULL;

	//second element
	struct Node *currentNode = list;

	while(currentNode != NULL) {
		temp = currentNode;
		currentNode = currentNode -> next;
		temp -> next = reversedList;
		reversedList = temp; 
	}

	return reversedList;
}

/*
 * min value in a list
 */
int min(struct Node* list) {
	if(list == NULL)
		return 0;

	int min;
	switch(list -> type) {
		case CHAR:
			min = (int)list -> c;
			break;
		case FLOAT:
			min = (int)list -> f;
                        break;
		case INT:
			min = list -> n;
                        break;
		case LIST:
			min = length(list -> l);
                        break;
		case STRING:
			min = strlen(list -> s);
                        break;
		default:
			break;
	}
	struct Node * currentnode = list;
	while(currentnode != NULL) {
		switch(currentnode  -> type) {
                	case CHAR:
				if(min > currentnode  -> c)
					min = currentnode  -> c;
				break;
                	case FLOAT:
				if(min > currentnode  -> f)
					min = (int) currentnode  -> f;
                                break;
                	case INT:
				if(min > currentnode  -> n)
					min = currentnode  -> n;
                                break;
                	case LIST:
				if(min > length(currentnode  -> l))
					min = length(currentnode  -> l);
                                break;
                	case STRING:
				if(min > strlen(currentnode  -> s))
					min = strlen(currentnode  -> s);
                                break;
			default:
				break;
        	}
		currentnode = currentnode -> next;
	}
	return min;
}

/*
 * max value in a list
 */
int max(struct Node* list) {
	if(list == NULL)
		return 0;

	int max;
	switch(list -> type) {
                case CHAR:
			max = (int)list -> c;
			break;
                case FLOAT:
			max = (int)list -> f;
                        break;
                case INT:
			max = list -> n;
                        break;
                case LIST:
			max = length(list -> l);
                        break;
                case STRING:
			max = strlen(list -> s);
                        break;
		default:
			break;
        }
	struct Node * currentnode = list;
	while(currentnode != NULL) {
		switch(currentnode -> type) {
                	case CHAR:
                                if(max < currentnode  -> c)
                                        max = currentnode  -> c;
                        	break;
                	case FLOAT:
                                if(max < currentnode  -> f)
                                        max = (int) currentnode  -> f;
                        	break;
                	case INT:
                                if(max < currentnode  -> n)
                                        max = currentnode  -> n;
                        	break;
                	case LIST:
                                if(max < length(currentnode  -> l))
                                        max = length(currentnode  -> l);
                        	break;
                	case STRING:
                                if(max < strlen(currentnode  -> s))
                                        max = strlen(currentnode  -> s);
                        	break;
			default:
				break;
        	}
		currentnode = currentnode -> next;
	}
	return max;
}

/*
 * length of a given list
 */
int length(struct Node * list) {
	if(list == NULL)
		return 0;
	int length = 0;
	struct Node * currentNode = list;
	while(currentNode != NULL){
		length++;
		currentNode = currentNode -> next;
	}
	return length;	
}

/*
 * JUST RETURNS THE LIST INSTEAD
 * SORTING A GIVEN LIST
 */
struct Node * binsort(struct Node * list) {
	return list;
}
/*END OF THE PROGRAM*/
