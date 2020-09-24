#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

void bury();
int counter = 0;

int main(){
	char* A[] = {"echo", "5", NULL};
	while(1){
		pid_t pid;
		if(counter < 5){
			counter++;
			pid = fork();
		}
		if(pid > 0){
			printf("ich bin vater des kindes %d\n",pid);
			bury();
			
		//	if(wait(&status) == pid){
		//		printf("Kind beendet ich terminiere mich %d\n",pid);
		//	} else {
		//		printf("Kind is tot \n");
		//	}
		} else {
			printf("ich bin das kind\n");
			printf("ich fuhre exec mit %s\n",A[0]);
			execvp(A[0],A);
			printf("etwas schief gegeangen\n");
		}
	}
}

void bury(){
	int status;
	pid_t pid;
	while(1){
		pid = waitpid(-1, &status, WNOHANG);
		if(pid > 0){
			printf("Kind pid : %d with status %d\n",pid, WEXITSTATUS(status));
			break;
		}
	}
}
