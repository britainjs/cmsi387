/**
 * Implementation (and privates) for critical-section functions.
 */
#include "philo-cs.h"
#include "philo.h"
#include "philo-sync.h"

#include <stdio.h>
#include <string.h>

int forkStatus[] = {1, 1, 1, 1, 1};
const char *nameList[] = {"Aristotle", "Locke", "Kant", "Kierkegaard", "Hobbes"};

int getForks(int philosopher) {
    int leftFork = left(philosopher);
    int rightFork = right(philosopher);
    sem_wait(forks[leftFork]);
    if(forkStatus[leftFork] < 1) {
        printf("*** CRITICAL SECTION VIOLATION ***\n");
        return -1;
    } else {
        forkStatus[leftFork] = 0;
    }
    printf("%s has fork %d\n", nameList[ philosopher ], leftFork);
    sem_wait(forks[rightFork]);
    if(forkStatus[rightFork] < 1) {
        printf("*** CRITICAL SECTION VIOLATION ***\n");
        return -1;
    } else {
        forkStatus[rightFork] = 0;
    }
    printf("%s has fork %d\n", nameList[ philosopher], rightFork);
    return 0;
}

int putForks(int philosopher) {
    int leftFork = left(philosopher);
    int rightFork = right(philosopher);
    
    if(forkStatus[leftFork] > 0) {
        printf("*** CRITICAL SECTION VIOLATION***\n");
        return -1;
    } else {
        forkStatus[leftFork] = 1;
    }
    
    sem_post(forks[leftFork] );
    printf("%s has put down fork %d\n", nameList[philosopher], leftFork);
    
    if(forkStatus[rightFork] > 0) {
        printf("*** CRITICAL SECTION VIOLATION***\n");
        return -1;
    } else {
        forkStatus[rightFork] = 1;
    }
    
    sem_post(forks[rightFork]);    
    printf("%s has put down fork %d\n", nameList[philosopher], rightFork);
    
    return 0;
}
