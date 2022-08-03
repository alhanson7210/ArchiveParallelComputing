#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
	if(argc < 2){
		printf("command line : program Word");
		return 0;
	}

	int size = strlen(argv[argc-1]);
	char word[size];
	for(int i = 0; i < size; i++){
		word[i] = argv[argc-1][i];
	}
	printf("%s", word);
	char temp[size];
	for(int i = 0; i < size; i++){
		temp[i] = word[i];
	}
	char *searchWord = temp;
	char sentence[100];
	printf("Enter a sentence with spaces:");
	gets(sentence);
	char *sent = sentence;
	int totalOccurrences = 0;
	int sizeOfWord = size;
	//printf("%d\n",sizeOfWord);		
	int i = 0;
	while(*(sent+i) != '\0') {
		if(*(sent + i) == *(searchWord)) {
			bool found = true;
			int z = 0;
			for(int j = i; j < i + sizeOfWord; j++) {
				//printf("%c == %c\t", *(sent + j), *(searchWord + z));
				if(*(sent + j) != *(searchWord + z)) {
					found = false;
					break;
				}
				z++;
			}
			if(found == false)
				printf("");
			else {
				totalOccurrences++;
				printf("\n%s was found starting at %d\n", word, i);
			}
		}
		i++;
	}	
	printf("\nTotal occurrences are %d\n", totalOccurrences);
	return 1;
}
