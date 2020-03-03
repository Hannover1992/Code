#include <fnmatch.h>
#include <stdio.h>

int main(int argc, char* argv[]){
	for(int i = 0; i < argc; i++){
		printf("%s", argv[i]);
		int j = fnmatch("aufgabe[0-9]", argv[i],0);
		printf("=%d\n",j);
	}
}
