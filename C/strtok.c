#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
	printf("hier");
	char bla[100] = "bla bla bla bla";
	const char* delimer = " ";
	char* part = strtok(bla, delimer);
	while(part != NULL){
		printf("%s\n",part);
		part = strtok(NULL, " \t");
	}
}


