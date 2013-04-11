/**
 * Producer implementation. Spits out philosophers
 */
#include "bb-cs.h"
#include "bb-sync.h"
#include "buffer.h"
#include "utility.h"

#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>

void exist(int producePhilo) {
    buffer_item item;
    while (1) {
        // Simulate a non-trivial produce.
        randomwait(producePhilo);
        printf("Produced %d.\n", item);

        sem_wait(empty);
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
