#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

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
    return 0;
	
}
