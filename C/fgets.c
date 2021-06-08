#include <stdio.h>
#include <stdlib.h>


int main(){
	char* input = malloc(100*sizeof(char));
	fgets(input, 100*sizeof(char), stdin);
	printf("%s\n", input);	
}
