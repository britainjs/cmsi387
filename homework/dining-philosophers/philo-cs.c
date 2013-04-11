/**
 * Implementation (and privates) for critical-section functions.
 */
#include "bb-cs.h"
#include "philo.h"

#include <stdio.h>
#include <string.h>

int* forkStatus = [1, 1, 1, 1, 1]

int getForks(int philosopher) {
    int leftFork = left(philosopher);
    int rightFork = right(philosopher);
    sem_wait(forks[leftFork]);
    if(!forkStatus[leftFork]) {
        printf("*** CRITICAL SECTION VIOLATION ***\n");
    } else {
        forkStatus[leftFork] = 0;
    }
    printf("%s has fork %d\n", names[ philosopher ], forks[leftFork]);
    sem_wait(forks[rightFork]);
    if(!forkStatus[rightFork]) {
        printf("*** CRITICAL SECTION VIOLATION ***\n");
        return -1;
    } else {
        forkStatus[rightFork] = 0;
    }
    printf("%s has fork %d\n", names[ philosopher], forks[rightFork]);
    return 0;
}

int putForks(int i) {
    int leftFork = left(philosopher);
    int rightFork = right(philosopher);
    sem_post(forks[leftFork] );
    printf("%s has put down fork %d\n", names[philosopher], forks[leftFork]);
    sem_post(forks[rightFork]);
    printf("%s has put down fork %d\n", names[philosopher], forks[rightFork]);
}

