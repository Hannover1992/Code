#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

void print_size(char* path){

	char* path_name = malloc(sizeof(path) + 2);
	path_name[0] = '.';
	path_name[1] = '/';
	for(int i = 0; i < strlen(path); i++){
		path_name[i+2] = path[i];
	}
	DIR* dir = opendir(path_name);
	struct dirent* e = NULL;
	struct stat file_info;

	while(((e = readdir(dir)) != NULL)){
		char* name = e->d_name;

		printf("%s: size=",name);
		lstat(name, &file_info);
		printf("%ld\n",file_info.st_size);
		if(S_ISDIR(file_info.st_mode)){

			if((strcmp(name, ".") == 0) || strcmp(name, "..") == 0){
				continue;
			}
			print_size(name);
		}
	}
}
int main(){
	print_size("test");

}
