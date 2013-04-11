/**
 * Synchronization primitive implementation.
 */
#include "philo-sync.h"

#include "philo.h"
#ifdef __APPLE_CC__
#include <fcntl.h>
#endif
#include <pthread.h>
#include <semaphore.h>

void initSync(void) {
    pthread_mutex_init(&mutex, NULL);
#ifndef __APPLE_CC__
    int i;
    for (i = 0; i < FORK_AMOUNT; i++) {
        forks[i] = &fork;
        sem_init(forks[i], 0, 1);
    }
    
#else
    /*
    sem_unlink("empty");
    sem_unlink("full");
    empty = sem_open("empty", O_CREAT, S_IRWXU, 1);
    full = sem_open("full", O_CREAT, S_IRWXU, 0);
    */
#endif
}
