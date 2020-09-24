#include <unistd.h>
#include <stdio.h>
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
	printf("%s\n",buffer);
	
	close(fd);
	close(fd1);
	free(buffer);
}

int foo2(){
//	still don't work no errors but also no write into the file
	/*
	char* buffer = malloc(100*sizeof(char));
	int n, a=5, b=3;
	n=sprintf (buffer, "%d plus %d is %d", a, b, a+b);
/	printf ("[%s] is a string %d chars long\n",buffer,n);
	int fd = open("text.txt", O_CREAT | O_WRONLY | O_APPEND, S_IRUSR | S_IWUSR);
	write(fd, buffer, 100);
	return 0;
	*/
}

int main(){
	foo1();
//	foo2();
}
