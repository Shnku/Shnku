#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
// #include <stdlib.h>
#include <unistd.h>
sem_t s1, s2, s3;

void *process_a(void *arg) {
    int k = 3;
    while (k) {
        int a, b, c;
        sem_getvalue(&s1, &a);
        sem_getvalue(&s2, &b);
        sem_getvalue(&s3, &c);
        printf("\n(%d,%d,%d)....in...p1", a, b, c);
        // sleep(1);

        sem_wait(&s3);
        printf("\nCRITICAL SECTION >> P1:: => c\n");
        // sleep(1);
        sem_post(&s2);

        sem_getvalue(&s1, &a);
        sem_getvalue(&s2, &b);
        sem_getvalue(&s3, &c);
        printf("\n(%d,%d,%d)....in...p1", a, b, c);
        k--;
        sleep(1);
    }
    return NULL;
}

void *process_b(void *arg) {
    int k = 3;
    while (k) {
        int a, b, c;

        sem_getvalue(&s1, &a);
        sem_getvalue(&s2, &b);
        sem_getvalue(&s3, &c);
        printf("\n(%d,%d,%d)....in...p2", a, b, c);
        // sleep(1);

        sem_wait(&s1);
        printf("\nCRITICAL SECTION >> P2:: => b\n");
        // sleep(1);
        sem_post(&s3);

        sem_getvalue(&s1, &a);
        sem_getvalue(&s2, &b);
        sem_getvalue(&s3, &c);
        printf("\n(%d,%d,%d)....in...p2", a, b, c);
        k--;
        sleep(1);
    }
    return NULL;
}

void *process_c(void *arg) {
    int k = 3;
    while (k) {
        int a, b, c;

        sem_getvalue(&s1, &a);
        sem_getvalue(&s2, &b);
        sem_getvalue(&s3, &c);
        printf("\n(%d,%d,%d)....in...p3", a, b, c);
        // sleep(1);

        sem_wait(&s2);

        printf("\nCRITICAL SECTION >> P3 :: => a\n");
        // sleep(1);
        sem_post(&s1);

        sem_getvalue(&s1, &a);
        sem_getvalue(&s2, &b);
        sem_getvalue(&s3, &c);
        printf("\n(%d,%d,%d)....in...p3", a, b, c);
        k--;
        sleep(1);
    }
    return NULL;
}

int main() {
    sem_init(&s1, 0, 1);
    sem_init(&s2, 0, 0);
    sem_init(&s3, 0, 0);

    int a, b, c;

    sem_getvalue(&s1, &a);
    sem_getvalue(&s2, &b);
    sem_getvalue(&s3, &c);
    printf("in main() s1,s2,s3 == %d,%d,%d\n", a, b, c);

    // sleep(1);
    pthread_t thread_a, thread_b, thread_c;
    pthread_create(&thread_a, NULL, process_a, NULL);
    pthread_create(&thread_b, NULL, process_b, NULL);
    pthread_create(&thread_c, NULL, process_c, NULL);

    pthread_join(thread_a, NULL);
    pthread_join(thread_b, NULL);
    pthread_join(thread_c, NULL);

    printf("\nreach end..");
    sem_destroy(&s1);
    sem_destroy(&s2);
    sem_destroy(&s3);

    return 0;
}

//output...............................
/*
in main() s1,s2,s3 == 1,0,0

(1,0,0)....in...p1
(1,0,0)....in...p3
(1,0,0)....in...p2
CRITICAL SECTION >> P2:: => b

(0,0,1)....in...p2
CRITICAL SECTION >> P1:: => c

(0,1,0)....in...p1
CRITICAL SECTION >> P3 :: => a

(1,0,0)....in...p3
(1,0,0)....in...p2
CRITICAL SECTION >> P2:: => b

(0,0,1)....in...p2
(0,0,1)....in...p3
(0,0,1)....in...p1
CRITICAL SECTION >> P1:: => c

(0,1,0)....in...p1
CRITICAL SECTION >> P3 :: => a

(1,0,0)....in...p3
(1,0,0)....in...p2
CRITICAL SECTION >> P2:: => b

(0,0,1)....in...p2
(0,0,1)....in...p1
CRITICAL SECTION >> P1:: => c

(0,1,0)....in...p1
(0,1,0)....in...p3
CRITICAL SECTION >> P3 :: => a

(1,0,0)....in...p3
reach end..
*/
