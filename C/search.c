    #include<stdio.h>
    #include<string.h>
    #include<stdlib.h>
    #include<regex.h>
    #include<sys/types.h>
    
    int main (){
    	//open file
    	FILE *file_pointer = fopen("./test_txt.txt", "r");
    	const char* search_for = "3_hau_gbs";
    	
    	int line_number = 1;
    	char* line = NULL;
    	size_t len = 0;
    
    	
    	regex_t regex;
    	int failed = regcomp(&regex, search_for, REG_EXTENDED);
    	//You are serching bitwise, so you must first semicompile it
    	if(failed){
    		regfree(&regex);
    	} else {
    		while(getline(&line, &len, file_pointer) != -1){
    			//go line after line and check if it include the word you 
    			//you are looking for
    			int match = regexec(&regex, line, 0, NULL, 0);
    			if(!match){
    				//when find so output
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
