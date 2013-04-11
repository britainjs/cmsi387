/**
 * Producer implementation. Spits out philosophers
 */
#include "philo-cs.h"
#include "philo-sync.h"
#include "philo.h"
#include "utility.h"

#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>

void exist(int philo) {
    while (1) {
        // Simulate the normal activities of a philosopher at dinner.
        //Think
        printf("%s is thinking...", names[philo]);
        randomwait(PHILOSOPHER_AMOUNT);
        
        getForks(philo);
        pthread_mutex_lock(&mutex);
        
        //Eat
        printf("%s is eating...", names[philo]);
        randomwait(PHILOSOPHER_AMOUNT);
        pthread_mutex_unlock(&mutex);
        
        putForks(philo);
        printf("%s is done.", names[philo]);
    }
}

int left(int philosopher) {
    return i;
}

int right(int philosopher) {
    return (i+1) % PHILOSOPHER_AMOUNT;
}

