#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct bli{
	int i;
	char** array;
}bli_t;

bli_t* foo(){

	bli_t *bla = malloc(sizeof(bli_t));
	bla->array = malloc(sizeof(char**));
	bla->array[0] = "blaa";
	bla->array[1] = "bluu";
	for(int i = 0; i < 2; i++){
		printf("%s\n",bla->array[i]);
	}
	return bla;
}
int main(){
	bli_t* bla = foo();
	for(int i = 0; i < 2; i++){
		printf("%s\n",bla->array[i]);
	}
}
