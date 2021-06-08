#include <unistd.h>
#include <limits.h>
#include <stdio.h>

int main(){
	char* wd;
	wd = getcwd(wd, PATH_MAX);
	if(wd == NULL){
		perror("Memo allo failesd\n");
	}
	printf("%s\n",wd);
}

