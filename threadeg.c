#include <stdio.h>
#include <pthread.h>
//#include <stdlib.h>

#define MAX_THREAD 2
#define MAX_VALUE 10

pthread_mutex_t mutex;
pthread_cond_t cond;
int count = 0;

typedef struct _Args {
	int max_value; 
} Args;

void *even(void *arg) {
	while (count < ((Args *)arg)->max_value) {
		pthread_mutex_lock(&mutex);
		while (count%2 != 0) {
			pthread_cond_wait(&cond, &mutex);
		}
		printf("%d ", count++);
		pthread_mutex_unlock(&mutex);
		pthread_cond_signal(&cond);
	}
	pthread_exit(0);
}
void *odd(void *arg) {
	while (count < ((Args *)arg)->max_value) {
		pthread_mutex_lock(&mutex);
		while (count%2 == 0) {
			pthread_cond_wait(&cond, &mutex);
		}
		printf("%d ", count++);
		pthread_mutex_unlock(&mutex);
		pthread_cond_signal(&cond);
	}
	pthread_exit(0);
}

void main() {

	int max_value, i, k;
	Args arg;
	printf("Enter number of value: ");
	scanf("%d", &arg.max_value);

	pthread_t thread[MAX_THREAD];

	for (int i = 0; i < MAX_THREAD; i++) {
		pthread_mutex_init(&mutex, 0);
	}

	for (int i = 0; i < MAX_THREAD; i++) {
		pthread_cond_init(&cond, 0);
	}

	// for (int i = 0; i < MAX_THREAD; i++) 
	{
		pthread_create(&thread[0], 0, &odd, (void *)&arg);
		pthread_create(&thread[1], 0, &even, (void *)&arg);

	}

	for (int i = 0; i < MAX_THREAD; i++) {
		pthread_join(thread[i], 0);
	}

	pthread_mutex_destroy(&mutex);
	pthread_cond_destroy(&cond);

	printf("\n");
}