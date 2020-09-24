#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>

void foo1(){
	printf("hier");
	char bla[100] = "bla bla bla bla";
	const char* delimer = " ";
	char* part = strtok(bla, delimer);
	while(part != NULL){
		printf("%s\n",part);
		part = strtok(NULL, " \t");
	}
}

void foo2(){
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




int main(){
	foo1();
	foo2();
}
