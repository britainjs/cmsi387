/**
 * A test harness for running solutions to the bounded buffer problem.
 */
#include <pthread.h>
#include <stdio.h>

#include "philo.h"
#include "philo-sync.h"

/* The test harness defines the expected interfaces. */
void *exist(int producePhilosopher);
const char *names[] = {"Aristotle", "Locke", "Kant", "Kierkegaard", "Hobbes"};
/**
 * Thread runner for the producer.
 */
void *sitDown(void *arg) {
    exist((int)arg);
    pthread_exit(NULL);
}

/**
 * Overall driver program.
 */

int main (int argc, char** argv) {
    printf("Starting Philosopher party...\n");
    
    initSync();
    
    pthread_t *philosophers = malloc(sizeof(pthread_t) * PHILOSOPHER_AMOUNT);
    
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    
    int i;
    for( i = 0; i < 5; i++ ) {
        pthread_create(&philosophers[i], &attr, sitDown, (void *)i);
        printf("%s has sat down\n", names[i]);
    }
    
    return 0;

}
