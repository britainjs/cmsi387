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
        // JD: The non-pointer sem_t's should be distinct also
        //     (i.e., they should also comprise an array of
        //     the number of philosophers/forks).
        forks[i] = &fork;
        sem_init(forks[i], 0, 1);
    }
#else
    // JD: The distinction in Mac OS X is that the operating
    //     system takes care of allocating the semaphores; it
    //     just gives you the pointers to them.  Thus, this
    //     code should pretty much be one sem_open per forks
    //     element.
    /*
    sem_unlink("empty");
    sem_unlink("full");
    empty = sem_open("empty", O_CREAT, S_IRWXU, 1);
    full = sem_open("full", O_CREAT, S_IRWXU, 0);
    */
#endif
}
