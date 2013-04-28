/**
 * Synchronization elements for a bounded buffer solution.
 */
#ifndef __PHILO_SYNC__
#define __PHILO_SYNC__

#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include "philo.h"

// JD: This is defined and initialized but unused.
//     Use it or lose it :)
pthread_mutex_t mutex;

// JD: 4?  Shouldn't this be FORK_AMOUNT?
//     (which should really be PHILOSOPHER_AMOUNT too...)
sem_t *forks[4];
#ifndef __APPLE_CC__
// JD: This should also be an array.
sem_t fork;
#endif

/**
 * Initializes synchronization primitives.
 */
void initSync(void);

#endif
