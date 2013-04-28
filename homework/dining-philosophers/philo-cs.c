/**
 * Implementation (and privates) for critical-section functions.
 */
#include "philo-cs.h"
#include "philo.h"
#include "philo-sync.h"

#include <stdio.h>
#include <string.h>

int forkStatus[] = {1, 1, 1, 1, 1};
// JD: Based on your last commit message, you were aware that this array
//     is unnecessarily duplicated, and you are right.  Did you try
//     putting this in a .h file that is included by both this file
//     and philo-harness.c?  That would be the way to do it.
const char *nameList[] = {"Aristotle", "Locke", "Kant", "Kierkegaard", "Hobbes"};

int getForks(int philosopher) {
    // JD: left and right, which were defined in producer.c, should
    //     be declared in a .h file which this file would #include.
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

