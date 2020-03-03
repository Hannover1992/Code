//compile with -pthread
#include<pthread.h>
static double a[100][100], b[100], c[100];

struct param {
	int index;
};
static void* mult(void *argv);

int main(int agrc, char* argv[]){
	pthread_t tids[100];
	struct param args[100];

	for(int i = 0; i < 100; i++){
		args[i].index = i;
		pthread_create(&tids[i], NULL, mult, &args[i]);
	}
	for(int i = 0; i < 100; i++){
		pthread_join(tids[i], NULL);
	}
}

static void* mult(void *arg){
	struct param *par = (struct param *) arg;

	double sum = 0;
	for(int j = 0; j < 100 ; j++){
		sum += a[par->index][j] * b[j];
	}
	c[par->index] = sum;
	return NULL;
}
