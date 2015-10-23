#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h> //para incluir estructuras timeval

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
	struct timeval tv1,tv2,tv3,tv4;
	clock_t t1, t2, t3, t4;

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
	//t1=clock();
	gettimeofday(&tv1, NULL);
	initialize_vector();
	gettimeofday(&tv2, NULL);
	//t2=clock();
	//printf("Vector initialized! - elapsed %lf\n", ( (double)(t2 -t1) )/CLOCKS_PER_SEC);
	printf("Vector initialized! - elapsed %lf sec.\n", (double) (tv2.tv_usec - tv1.tv_usec) / 1000000 +
	         (double) (tv2.tv_sec - tv1.tv_sec));
	fflush(stdout);
	//t3 = clock();
	gettimeofday(&tv3, NULL);
	count_3s();
	gettimeofday(&tv4, NULL);
	//t4 = clock();
	printf("Count by threads %d\n", count);
	printf("Double check %d\n", double_count);
	//printf("[[3s-00] Elapsed time %lf\n", ( (double)(t4-t3) )/ CLOCKS_PER_SEC );
	printf("[[3s-00] Elapsed time %lf sec.\n", (double) (tv4.tv_usec - tv3.tv_usec) / 1000000 +
	         (double) (tv4.tv_sec - tv3.tv_sec));
	printf("Finishing 3s-00\n");
	return 0;
}
