#include <stdlib.h>
#include <stdio.h>

int main(){
	//test_concate();
	char* intager1 = "123456";
	char* intager2 = "123456";
	int val1 = strtol(intager1,&intager1,10);
	int val2 = strtol(intager2,&intager2,10);
	printf("%d\n",val1 + val2);

}
