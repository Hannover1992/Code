#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	char* input = malloc(124);
	int size = 124; 
	fgets(input, size, stdin);
	printf("%s\n",input);
}
