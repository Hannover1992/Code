#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
	char* a = "bla";
	char* b = "bli";
	char* concat = malloc(sizeof(a) + sizeof(b));
	strcat(concat,a);
	strcat(concat,b);
	printf("%s\n",concat);
	return 0;
}
