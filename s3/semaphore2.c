#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

sem_t s0, s1, s2;

void *p0() {
    printf("enter p0\n");
    while (1) {
        sem_wait(&s0);
        printf("0\n");
        // sleep(1);
        sem_post(&s1);
        sem_post(&s2);
    }
    printf("exit p0\n");
}

void *p1() {
    printf("enter p1\n");
    sem_wait(&s1);
    sem_post(&s0);
    printf("exit p1\n");
    return NULL;
}

void *p2() {
    printf("enter p2\n");
    sem_wait(&s2);
    sem_post(&s0);
    printf("exit p2\n");
    return NULL;
}

int main() {
    sem_init(&s0, 0, 1);
    sem_init(&s1, 0, 0);
    sem_init(&s2, 0, 0);

    pthread_t t1, t2, t3;
    pthread_create(&t1, NULL, p0, NULL);
    pthread_create(&t2, NULL, p1, NULL);
    pthread_create(&t3, NULL, p2, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);

    // pthread_exit(NULL);
    printf("comes out\n");  // doesnot execute...
    sem_destroy(&s0);
    sem_destroy(&s1);
    sem_destroy(&s2);

    return 0;
}


//output..
/*
enter p0
0
enter p1
exit p1
0
enter p2
exit p2
0
^C
*/
