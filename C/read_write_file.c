#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void foo1(){
	ssize_t nrd;
	int fd;
	int fd1;

	char* buffer = malloc(100*sizeof(char));
	fd = open("bli.txt", O_RDONLY);
	fd1 = open("bla.txt", O_CREAT | O_WRONLY | O_APPEND, S_IRUSR | S_IWUSR);
	while (nrd = read(fd,buffer,sizeof(buffer))) {
		write(fd1,buffer,nrd);
	}
	
	close(fd);
	close(fd1);
	free(buffer);
}

int foo2(){
	char* buff = malloc(100*sizeof(char));
}
int main(){
	foo1();
//	foo2();
}
