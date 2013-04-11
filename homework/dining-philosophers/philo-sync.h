/**
 * Synchronization elements for a bounded buffer solution.
 */
#ifndef __PHILO_SYNC__
#define __PHILO_SYNC__

#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include "philo.h"

pthread_mutex_t mutex;
sem_t *forks[4];
#ifndef __APPLE_CC__
sem_t fork;
#endif

/**
 * Initializes synchronization primitives.
 */
void initSync(void);

#endif
