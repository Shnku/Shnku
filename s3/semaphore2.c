#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>

sem_t s0, s1, s2;

void *p0() {
    printf("enter p0\n");
    while (1) {
        sem_wait(&s0);
        printf("p0 in cs ......0\n");
        sem_post(&s1);
        sem_post(&s2);
    }
    printf("exit p0\n");
    return NULL;
}

void *p1() {
    printf("enter p1\n");
    sem_wait(&s1);
    printf("p1 in cs....1\n");
    sem_post(&s0);
    printf("exit p1\n");
    return NULL;
}

void *p2() {
    printf("enter p2\n");
    sem_wait(&s2);
    printf("p2 in cs....2\n");
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


//output.. not only this others anything is possible....
/*
enter p0
p0 in cs ......0
enter p1
enter p2
p1 in cs.......1
exit p1
p0 in cs ......0
p2 in cs.......2
exit p2
p0 in cs ......0
.
.
enter p1
enter p2
enter p0
p0 in cs ......0
p1 in cs.......1
exit p1
p2 in cs.......2
exit p2
p0 in cs ......0
p0 in cs ......0
*/
//they can enter in any time in ready queue ..
