#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

void invalid_argu(void){
	errno = EINVAL;
	perror("");
}

void exit_failure(){
	perror("open dir");
	exit(EXIT_FAILURE);
}

void stder(){
	printf("first\n");
	fprintf(stderr, "%s\n", "Something");
	printf("second\n");
}
int main (){
//	invalid_argu();
//	exit_failure();
	stder();
}
