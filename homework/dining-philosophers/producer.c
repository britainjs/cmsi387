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
        // Simulate a non-trivial produce.
        randomwait(philo);
        getForks(philo);
        pthread_mutex_lock(&mutex);
        if (insert_item(item)) {
            fprintf(stderr, "***** Insert failed!\n");
            pthread_mutex_unlock(&mutex);
            return;
        }
        pthread_mutex_unlock(&mutex);
        sem_post(full);
    }
}

int left(int philosopher) {
    return i;
}

int right(int philosopher) {
    return (i+1) % PHILOSOPHER_AMOUNT;
}

