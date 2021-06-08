#include <time.h>


int main(){
	clock_t start = clock();
	/*Do something*/
	clock_t end = clock();
	float seconds = (float)(end - start) / CLOCKS_PER_SEC;
	printf("%f\n", seconds);
}
