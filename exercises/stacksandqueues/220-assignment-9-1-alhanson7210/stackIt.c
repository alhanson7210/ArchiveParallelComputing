//libraries
#include <stdio.h>
#include <stdlib.h>
//structures
/*student records represented as a linked list of all their scores*/
struct Record {
	struct Record *nextRecord;
	int data;
};
/*student representation*/
struct Student {
	struct Student *nextStudent;
	struct Record *nextRecord;
	int studentNumber;
	int bestScore;	
};
//prototypes
struct Student * push(struct Student *studentsList, struct Student *newStudent);
struct Student * pop(struct Student *studentsList);
void showStack(struct Student *studentsList);
void showStackRecords(struct Student *student);
struct Student * insert(struct Student *studentsList, struct Student *newStudent);
struct Student * delete(struct Student *studentsList);
void showQueue(struct Student *studentsList);
void showQueueRecords(struct Student *student);
//driver
int main(void) {
	/*instance variables*/
	int problemNumber = 0, menuOptionNumber = 0, id = 0, score = 0, BestScore = 0;
	//char addScore = 'y';
	struct Student *studentsListStack = NULL;//malloc(sizeof(struct Student));
	
	//studentsListStack -> nextStudent = NULL;
	//studentsListStack -> nextRecord = NULL;

	struct Student *studentsListQueue = NULL;//malloc(sizeof(struct Student));
        
	//studentsListStackQueue -> nextStudent = NULL;
        //studentsListStackQueue -> nextRecord = NULL;
	
	while(problemNumber != 3){
		printf("Please enter a problem number:\n1. StackIt\n2. QueueIt\n3. Exit\nOption:");
		scanf("%d",&problemNumber);
		switch(problemNumber){
			case 1:
				menuOptionNumber = 0;
				while(menuOptionNumber != 4) {
					printf("\nPlease enter a menu option:\n1. Add new student \n2. Remove a student\n3. Show the current students list\n4. exit\nOption:");
					scanf("%d", &menuOptionNumber);
					switch(menuOptionNumber) {
						case 1:
							id = 0, score = 0, BestScore = 0;

							struct Record *newRecord = malloc(sizeof(struct Record));
							struct Student *newStudent = malloc(sizeof(struct Student)); 
							struct Record *temp = malloc(sizeof(struct Record));
							
							printf("\nEnter the student id:");
							scanf("%d", &id);
							newStudent -> studentNumber = id;
							
							printf("\nEnter the student's score:");
                                                        scanf("%d", &score);
							newRecord -> data = score;
							newRecord -> nextRecord = NULL;
							BestScore = score;
							/*printf("Do you want to add another score for this student(y or Y for yes and n or N for no):");
							scanf("%c", &addScore);
							while(addScore != 'N' || addScore != 'n'){
								printf("\nEnter the student's score:");
								scanf("%d", &score);
								if(score > BestScore)
									BestScore = score;
								temp -> nextRecord = newRecord;
								temp -> data = score;
								newRecord = temp;
								printf("Do you want to add another score for this student(y or Y for yes and n or N for no):");
								scanf("%c", &addScore);
							}*/
							newStudent -> nextRecord = newRecord;
							newStudent -> bestScore = BestScore;
							studentsListStack = push(studentsListStack, newStudent);
							break;
						case 2:
							studentsListStack = pop(studentsListStack);
							break;
						case 3:
							showStack(studentsListStack);
							break;
						case 4:
							break;
						default:
							menuOptionNumber = 4;
					}
				}
				break;
			case 2:
				menuOptionNumber = 0;
				while(menuOptionNumber != 4) {
					printf("\nPlease enter a menu option:\n1. Insert new student\n2. Remove a student\n3. Show the current student list\n4. Exit\nOption:");
                                        scanf("%d", &menuOptionNumber);
                                        switch(menuOptionNumber) {
                                                case 1:
                                                        id = 0, score = 0, BestScore = 0;

                                                        struct Record *newRecord = malloc(sizeof(struct Record));
                                                        struct Student *newStudent = malloc(sizeof(struct Student));
                                                        struct Record *temp = malloc(sizeof(struct Record));

                                                        printf("\nEnter the student id:");
                                                        scanf("%d",&id);
                                                        newStudent -> studentNumber = id;

                                                        printf("\nEnter the student's score:");
                                                        scanf("%d", &score);
                                                        newRecord -> data = score;
                                                        newRecord -> nextRecord = NULL;
                                                        BestScore = score;

                                                        /*while(addScore != 'N' || addScore != 'n'){
								printf("Do you want to add another score for this student(y or Y for yes and n or N for no):");
                                                                scanf("%c", &addScore);
                                                                if(addScore == 'N' || addScore == 'n')
                                                                        break;
                                                                printf("\nEnter the student's score:");
                                                                scanf("%d", &score);
                                                                if(score > BestScore)
                                                                        BestScore = score;
                                                                temp -> nextRecord = newRecord;
                                                                temp -> data = score;
                                                                newRecord = temp;
                                                        }*/
                                                        newStudent -> nextRecord = newRecord;
                                                        newStudent -> bestScore = BestScore;
							studentsListQueue = insert(studentsListQueue, newStudent);
                                                        break;
                                                case 2:
							studentsListQueue = delete(studentsListQueue);
                                                        break;
                                                case 3:
							showQueue(studentsListQueue);
                                                        break;
                                                case 4:
                                                        break;
                                                default:
                                                        menuOptionNumber = 4;
                                        }
				}
				break;
			case 3:
				break;
			default:
				problemNumber = 3;
		}
	}
	//exit 1 for success
	return 1;
}
//functions
/*place new node at the end of the linked list*/
struct Student * push(struct Student *studentsList, struct Student *newStudent) {
	if(studentsList == NULL){
		studentsList = newStudent;
		return studentsList;
	}
	struct Student *currentStudent = studentsList;
	while(currentStudent -> nextStudent != NULL){
		currentStudent = currentStudent -> nextStudent;
	}
	currentStudent -> nextStudent = newStudent;
	return studentsList;
}
/*remove node from the end of the linked list*/
struct Student * pop(struct Student *studentsList) {
	//no elements
	if(studentsList == NULL)
		return studentsList;
	//one
	if(studentsList -> nextStudent == NULL){
		studentsList = NULL;
		return studentsList;
	}
	//two or more
	struct Student *currentStudent = studentsList;
	struct Student *NextStudent = studentsList -> nextStudent;
        while(NextStudent -> nextStudent != NULL){
                currentStudent = NextStudent;
		NextStudent = NextStudent -> nextStudent;
        }
	currentStudent -> nextStudent = NULL;
	return studentsList;
}
/*display the linked list of students and there records*/
void showStack(struct Student *studentsList) {
	if(studentsList == NULL)
                return;
        struct Student *currentStudent = studentsList;
        while(currentStudent != NULL){
		printf("\nStudent number %d has a best score of %d.\nThis student's score record consists of:", currentStudent -> studentNumber, currentStudent -> bestScore);
		printf("{");
		showStackRecords(currentStudent);
		printf("}");
		currentStudent = currentStudent -> nextStudent;
	}
}
/**/
void showStackRecords(struct Student *student) {
	if(student == NULL)
		return;
	struct Record *currentRecord = student -> nextRecord;
	while(currentRecord != NULL){
		printf(" %d ", currentRecord -> data);
		currentRecord = currentRecord -> nextRecord;
	}
}
/*enqueue at the beginning of the linked list*/
struct Student * insert(struct Student *studentsList, struct Student *newStudent) {
	if(studentsList == NULL){
                studentsList = newStudent;
		return studentsList;
	}
	newStudent -> nextStudent = studentsList;
	studentsList = newStudent;
	return studentsList;
}
/*dequeue at the end of the linked list*/
struct Student * delete(struct Student *studentsList) {
	if(studentsList == NULL)
		return studentsList;
	if(studentsList -> nextStudent == NULL)
		studentsList = NULL;
	
	struct Student *currentStudent = studentsList;
        struct Student *NextStudent = studentsList -> nextStudent;
	while(NextStudent -> nextStudent != NULL){
		currentStudent = NextStudent;
		NextStudent = NextStudent -> nextStudent;
	}
	currentStudent -> nextStudent = NULL;
	return studentsList;
}
/**/
void showQueue(struct Student *studentsList) {
	if(studentsList == NULL)
                return;
	struct Student *currentStudent = studentsList;
        while(currentStudent != NULL){
                printf("\nStudent number %d has a best score of %d.\nThis student's score record consists of:", currentStudent -> studentNumber, currentStudent -> bestScore);
                printf("{");
		showQueueRecords(currentStudent);
		printf("}");
                currentStudent = currentStudent -> nextStudent;
        }
}
/**/
void showQueueRecords(struct Student *student) {
        if(student == NULL)
                return;
        struct Record *currentRecord = student -> nextRecord;
        while(currentRecord != NULL){
                printf(" %d ", currentRecord -> data);
		currentRecord = currentRecord -> nextRecord;
        }
}
//END OF THE PROGRAM
