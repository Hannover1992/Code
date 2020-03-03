#include <stdio.h>

int main(){
	char* line = malloc(1000*sizeof(char));
	fgets(line, 1000*sizeof(char), stdin);
	printf("%s\n",line);
	printf("%ld\n",strlen(line));
}
