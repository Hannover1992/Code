#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<regex.h>
#include<sys/types.h>

int main (){
	FILE *file_pointer = fopen("./test_txt.txt", "r");
//	int c;
//	while(1){
//		c = fgetc(file_pointer);
//		if(feof(file_pointer)){
//			break;
//		}
//		printf("%c",c);
	const char* search_for = "3_hau_gbs";
	
	int line_number = 1;
	char* line = NULL;
	size_t len = 0;

	
	regex_t regex;
	int failed = regcomp(&regex, search_for, REG_EXTENDED);
	if(failed){
		regfree(&regex);
	} else {
		while(getline(&line, &len, file_pointer) != -1){
//			printf("%s\n",line);
			int match = regexec(&regex, line, 0, NULL, 0);
			if(!match){
				printf("%d:%s",line_number, line);
			}
			line_number++;
		}
		if(line){
			free(line);
		}
		regfree(&regex);
		fclose(file_pointer);
	}
}
