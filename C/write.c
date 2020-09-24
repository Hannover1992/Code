#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>

#include <sys/types.h>
#include <sys/wait.h>

mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;

void ewof(){
	pid_t pid = fork();
	int pipe1[2];
	int pipe2[2];
	int i = pipe(pipe1);
	int i2 = pipe(pipe2);
	char* argv[] = {"seq", "10", NULL};

	if(pid > 0){
		int status;
		if(wait(&status) == pid){
			printf("Das Kind %d hat normal terminiert\n",WEXITSTATUS(status));
		} else {
			printf("Das Kind hat nicht normal terminiert status %d\n",WEXITSTATUS(status));
		}
	} else if (pid == 0){
		int fd = creat("./bli.txt", 00400 | 00200 | 00040 | 00020 | 00004 | 00002 | O_APPEND);
		int fd2 = creat("./bli2.txt", 00400 | 00200 | 00040 | 00020 | 00004 | 00002 | O_APPEND);
		if(fd == -1)
		{
			perror("File createon of %s filed:\n");
			exit(EXIT_FAILURE);
		}

		dup2(fd, STDOUT_FILENO);
		dup2(fd2, STDOUT_FILENO);
//		dup2(fd, pipe1[1]);
//		dup2(fd2, pipe2[1]);
//		close(pipe1[1]);
//		close(pip
		close(fd);
		execvp(argv[0], argv);
	}
}

int ws(){

    int file = open("outfile",
        O_CREAT | O_RDWR | O_APPEND,
        S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH );
    int file2 = open("outfile",
        O_CREAT | O_RDWR | O_APPEND,
        S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH );
	int pipe1[2];
	pipe(pipe1);

    if (file < 0)
    {
        fprintf(stderr, "open error: %d [%s]\n", errno, strerror(errno));
        exit(1);
    }
//	dup2(pipe1[1],1);
//    dup2(pipe1[1],1);
	dup2(file,1);
    close(file);
    int ret = execl("/bin/ls","ls","-1",(char *)0);

    return 0;
}


int main(){
//	ewof();//exec an command and wirte the output in the file
	ws();//write_something

	
}
