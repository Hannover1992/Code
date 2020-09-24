#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

void pipe1(void){
    int pipefd[2];
    pid_t pid;

    int num = 0;

    pipe(pipefd);

    pid = fork();

    if(pid > 0){ // do parent stuff
        close(pipefd[0]); // close the reading end

        num = 5;

        write(pipefd[1], &num, sizeof(num)); // write on the writing end
        printf("Parent with pid %d sent value: %d\n", getpid(), num);

    }else{ // do child stuff
        close(pipefd[1]); // close the writing end

        read(pipefd[0], &num, sizeof(num)); // read on the reading end
        printf("Child with pid %d received value: %d\n", getpid(), num);

        exit(0);
    }
}

void pipe2(int argc, char* argv[]){
	int pipefd[2];
	pid_t pid;
	char buf;

	pipe(pipefd);
	pid = fork();
	if(pid > 0){
		close(pipefd[1]);//close write end
		while(read(pipefd[0], &buf, 1) > 0)
			write(STDOUT_FILENO, &buf, 1);
		write(STDOUT_FILENO, "\n", 1);
		close(pipefd[0]);

	} else if (pid == 0){
		close(pipefd[0]);
		write(pipefd[1], argv[1], strlen(argv[1]));
		close(pipefd[1]);
		wait((int*)NULL);
	}
}

int main(int argc, char *argv[]) {
//	void pipe1();
	pipe2(argc, argv);

    return 0;
	
}

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;

int main(){
	pid_t pid;
	int fd[2];

	pid = fork();
	if(pipe(fd) == 0){
		if(pid > 0){
			close(fd[1]);
			dup2(fd[0],0);
			char* args[] = {"bin/ls", NULL};
			int file = creat("./bla.txt", mode);
			dup2(file, 1);
			execvp(args[0], args);
		} else {
			close(fd[0]);
			dup2(fd[1], STDOUT_FILENO);
			char* args2[] = {"bin/wc","-l",NULL};
			execvp(args2[0], args2);
		}
	} else {
		perror("problem");
	}
}
