#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

#include <sys/stat.h>
#include <sys/types.h>
void read_dir(char* path_old){
	char* path = malloc(sizeof(path_old) + 3);
	strcat(path,"./");
	strcat(path,path_old);
	DIR* dir = opendir(path);
	struct dirent* e = NULL;
	while((e = readdir(dir))){
		char* name = e->d_name;
		if(strcmp(name,".") == 0 || strcmp(name, "..") == 0){
			continue;
		}
		printf("%s\n",name);
		struct stat file_info;
		lstat(path, &file_info);
		mode_t mode = file_info.st_mode;
		if(S_ISDIR(mode)){
			char* path_whole = malloc(sizeof(path) + 1 + sizeof(name));
			strcat(path_whole, path);
			strcat(path_whole, "/");
			strcat(path_whole, name);
			read_dir(path_whole);
		}
	}
}

int main(){
	read_dir("test");
}
