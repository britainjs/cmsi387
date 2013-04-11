/**
 * Definitions for critical-section functions and shared resources.
 */
#ifndef __PHILO_CS__
#define __PHILO_CS__

#include "philo.h"

/**
 * Attempts to pick up the adjacent forks.
 */
int getForks(int philosopher);

/**
 * Puts down the adjacent forks
 */
int putForks(int philosopher);
    
#endif
