#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
	char* A[] = {"sleep", "5", NULL};
	pid_t pid = fork();
	if(pid > 0){
		int status;
		if(wait(&status) == pid){
			printf("Kind beendet ich terminiere mich %d\n",pid);
		} else {
			printf("Kind is tot \n");
		}
	} else {
		printf("ich bin das kind\n");
		printf("ich fuhre exec mit %s\n",A[0]);
		execvp(A[0],A);
		printf("etwas schief gegeangen\n");
	}


}
