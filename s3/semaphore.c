#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <threads.h>
#include <unistd.h>

sem_t s1, s2, s3;

void *process_a(void *arg) {
    while (1) {
        sem_wait(&s3);
        printf("c\n");
        sleep(1);
        sem_post(&s2);
    }
    return NULL;
}

void *process_b(void *arg) {
    while (1) {
        sem_wait(&s1);
        printf("b\n");
        sleep(1);
        sem_post(&s3);
    }
    return NULL;
}

void *process_c(void *arg) {
    while (1) {
        sem_wait(&s2);
        printf("a\n");
        sleep(1);
        sem_post(&s1);
    }
    return NULL;
}

int main() {
    sem_init(&s1, 0, 1);
    sem_init(&s2, 0, 0);
    sem_init(&s3, 0, 0);

    pthread_t thread_a, thread_b, thread_c;

    pthread_create(&thread_a, NULL, process_a, NULL);
    pthread_create(&thread_b, NULL, process_b, NULL);
    pthread_create(&thread_c, NULL, process_c, NULL);

    pthread_join(thread_a, NULL);
    pthread_join(thread_b, NULL);
    pthread_join(thread_c, NULL);

    sem_destroy(&s1);
    sem_destroy(&s2);
    sem_destroy(&s3);

    return 0;
}

//output...
/*

b
c
a
b
c
a
b
c
a
b
c
a
b
c
a
*/
