#include <stdio.h>
#include <assert.h>
int sum(int n){
	int sum = 0;
	for(int i = n; i > 0; i--){
		sum += i;
	}
	return sum;
}

void print_numbers(int line){
	int last_step = 1;
	int step = 2;

	int counter = 1;
	int number = 1;
	int last_number = 1;
	int step_temp;
	int temp;

	for(int i=0; i<line; i++){
		for(int i2 = 0; i2 < counter; i2++){
			printf("%d|",number + i2*2);
		}
		int new_step = step + last_step;
		last_step = step;
		step = new_step;
		printf("last_step:%d,step:%d\n",last_step,step);
		printf("\n");
		counter++;

		number = number + step;
	}
}

void test_int(int i, int j){
	if(i == j){
		printf("passed\n");
	} else {
		printf("%d differ %d\n",i,j);
	}
}

int main(){
	
}

