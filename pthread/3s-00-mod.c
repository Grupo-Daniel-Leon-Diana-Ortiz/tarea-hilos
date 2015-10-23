#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_THREADS 4
#define VECTOR_SIZE 1000000000

pthread_t tid[MAX_THREADS];

int *array;
int count = 0;
int double_count = 0;
int max_threads = 0;


void initialize_vector() {
	int i = 0;
	array = (int*) malloc(sizeof(int) * VECTOR_SIZE);
	if (array == NULL) {
		printf("Allocation memory failed!\n");
		exit(-1);
	}
	for (; i < VECTOR_SIZE; i++) {
		array[i] = rand() % 20;
		if (array[i] == 3)
			double_count++;
	}
}

void count_3s() {
	int i = 0;
	for (; i < VECTOR_SIZE; i++) {
		if (array[i] == 3) count++;
	}
}

int main(int argc, char* argv[]) {
	int i = 0;
	int err;
	clock_t t1, t2, t3, t4;//se añaden dos variables para contar el tiempo de ejecución en cada caso.

	if (argc == 2) {
		max_threads = atoi(argv[1]);
	} else {
		max_threads = MAX_THREADS;
	}
	printf("Running 3s-00");
	// random seed
	// http://stackoverflow.com/questions/822323/how-to-generate-a-random-number-in-c
	srand(time(NULL));
	printf("*** 3s-00 ***\n");
	printf("Initializing vector... ");
	fflush(stdout);
	t1=clock();
	initialize_vector();
	t2=clock();
	//se usa la diferencia de los tiempos, antes y después de ejecutar la funcion de inicializacion
	//y se divide por la constante CLOCKS_PER_SEC (esta incluida en la librería time.h)
	printf("Vector initialized! - elapsed %f\n", ( (float)t2 - (float)t1 )/CLOCKS_PER_SEC);
	fflush(stdout);
	t3 = clock();
	count_3s();
	t4 = clock();
	printf("Count by threads %d\n", count);
	printf("Double check %d\n", double_count);
	printf("[[3s-00] Elapsed time %f\n", ( (float)t4 - (float)t3 ) / CLOCKS_PER_SEC );
	printf("Finishing 3s-00\n");
	return 0;
}
