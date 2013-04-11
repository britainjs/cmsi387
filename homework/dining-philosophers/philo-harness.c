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
    produce((int)arg);
    pthread_exit(NULL);
}

/**
 * Overall driver program.
 */

int main (int argc, char** argv) {
    printf("Starting Philosopher party...\n");
    
    initSync();
    
    pthread *philosophers = malloc(sizeof(pthread) * PHILOSOPHER_AMOUNT);
    char** names = ["Aristotle", "Locke", "Kant", "Kierkegaard", "Hobbes"];
    
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    
    int i;
    for( i = 0; i < 5; i++ ) {
        pthread_create(&philosophers[i], &attr, sitDown, (void *)i);
        printf("%s has sat down", names[i]);
    }
    
    return 0;

}
