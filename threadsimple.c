#include <stdio.h>
#include <pthread.h>

#define MAX_COUNT 20
pthread_cond_t cond;
pthread_mutex_t mutex;
int count;


void* even(void *arg) {
    while (count < MAX_COUNT) {
        pthread_mutex_lock(&mutex);
        if(count %2 != 0) {
            pthread_cond_wait(&cond, &mutex);
        }
        printf("%d ", count++);
        pthread_mutex_unlock(&mutex);
        pthread_cond_signal(&cond);
    }

    pthread_exit(0);
    
}

void* odd(void *arg) {
    while (count < MAX_COUNT) {
        pthread_mutex_lock(&mutex);
        if(count %2 == 0) {
            pthread_cond_wait(&cond, &mutex);
        }
        printf("%d ", count++);
        pthread_mutex_unlock(&mutex);
        pthread_cond_signal(&cond);
    }

    pthread_exit(0);
}

int main () {

    pthread_t thread[2];

    pthread_mutex_init(&mutex, 0);
    pthread_cond_init(&cond, 0);

    pthread_create(&thread[0], 0, &odd, 0);
    pthread_create(&thread[1], 0, &even, 0);

    pthread_join(thread[0], 0);
    pthread_join(thread[1], 0);


    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);


    printf("\n");
    return 0;
}