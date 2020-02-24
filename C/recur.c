#include<stdio.h>
#include<dirent.h>
#include<string.h>
#include<stdlib.h>
#include<sys/stat.h>

void recur_print(char* path){
	DIR* dir = opendir(path);

	struct dirent* e = NULL;
	while((e = readdir(dir)) != NULL){
		char* name = e->d_name;
		if(strcmp(name,".") == 0 || strcmp(name,"..") == 0){
			continue;
		}

		char* current_path;
		size_t lenPath = strlen(path);
		size_t lenName = strlen(name);
		current_path = malloc(lenPath + 1 + lenName + 1);
		if(current_path == NULL) return;
		memcpy(current_path, path, lenPath);
		memcpy(current_path + lenPath, "/", 1);
		memcpy(current_path + lenPath + 1, name, lenName + 1);

		struct stat buffer;
		stat(current_path, &buffer);

		mode_t type = buffer.st_mode;
		if(!S_ISDIR(type) && !S_ISREG(type)){
			continue;
		}
		printf("%s\n", current_path);
		if(S_ISDIR(type)){
			recur_print(current_path);
		}
		
	}
		

	closedir(dir);
}

int main(int argc,char* argv[]){
	printf("%s\n",argv[1]);
	recur_print(argv[1]);
}
