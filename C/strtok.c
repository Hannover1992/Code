#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main(){
	char* input = malloc(124*sizeof(char));
	fgets(input, 124, stdin);
	printf("%d\n",strlen(input));
	printf("%s\n", input);
	char* part = strtok(input, " \n");
	while(part != NULL){
		printf("%s\n",part);	
		part = strtok(NULL, " \n");
	}
}
