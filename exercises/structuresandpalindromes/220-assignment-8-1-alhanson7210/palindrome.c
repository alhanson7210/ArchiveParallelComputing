//libraries
#include <stdio.h>
#include <stdlib.h>
//structures
/*No structures used*/
//prototypes
int palindrome(char * string);
//driver
int main(void){
	char * string =  malloc(100*sizeof(char));
	printf("\nPlease enter a word or phrase that will be checked as a palindrome: ");
	gets(string);
	palindrome(string) == 1? printf("\n'%s' is a palindrome.\n", string) : printf("\n'%s' is not a palindrome.\n", string);
}
/*Function Declarations*/
int palindrome(char * string){
	int firstIdx = 0, lastIdx = 0;
	while(*(string+lastIdx) != '\0') {
		lastIdx++;
	}
	lastIdx--;	
	while(firstIdx != lastIdx && firstIdx < lastIdx){
		if(*(string+firstIdx) != *(string+lastIdx))
			return 0;
		firstIdx++, lastIdx--;
	}
	return 1;		
}
/*
index tests:
weew
0123
true

werew
01234
true

worw
0124
false

word
0123
false
*/
