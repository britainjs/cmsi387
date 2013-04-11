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

const char *philosophers[] = {"Aristotle", "Locke", "Kant", "Kierkegaard", "Hobbes"};

void exist(int philo) {
    while (1) {
        // Simulate the normal activities of a philosopher at dinner.
        //Think
        printf("%s is thinking...\n", philosophers[philo]);
        randomwait(PHILOSOPHER_AMOUNT);
        
        getForks(philo);
        pthread_mutex_lock(&mutex);
        
        //Eat
        printf("%s is eating...\n", philosophers[philo]);
        randomwait(PHILOSOPHER_AMOUNT);
        pthread_mutex_unlock(&mutex);
        
        putForks(philo);
        printf("%s is done.\n", philosophers[philo]);
    }
}

int left(int philosopher) {
    return philosopher;
}

int right(int philosopher) {
    return (philosopher+1) % PHILOSOPHER_AMOUNT;
}

