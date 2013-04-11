/**
 * A test harness for running solutions to the bounded buffer problem.
 */
#include <pthread.h>
#include <stdio.h>

#include "philo-sync.h"

/* The test harness defines the expected interfaces. */
void *exist(int producePhilosopher);

/**
 * Thread runner for the producer.
 */
void *sitDown(void *arg) {
    printf("Starting philosopher\n");
    produce((int)arg);
    printf("Ending philosopher\n");
    pthread_exit(NULL);
}

/**
 * Overall driver program.
 */

int main (int argc, char** argv) {
    printf("Starting Philosopher party...\n");
    
    initSync();
    
    pthread *philosophers = malloc(sizeof(pthread) * 5);
    
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    
    int i;
    for( i = 0; i < 5; i++ ) {
        pthread_create(&philosophers[i], &attr, sitDown, (void *)5);
    }
    
    return 0;

}
