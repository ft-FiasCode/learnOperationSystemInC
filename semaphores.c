#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <stdlib.h>

#define NUM_THREADS 5
#define SHARED_RESOURCE 100

sem_t mutex;  // Binary semaphore for mutual exclusion
int shared_counter = 0;

void* thread_function(void* arg) {
    int thread_id = *(int*)arg;
    
    while(shared_counter < SHARED_RESOURCE) {
        // Wait (P operation) - acquire semaphore
        sem_wait(&mutex);
        
        // Critical Section
        int temp = shared_counter;
        printf("Thread %d: Counter = %d\n", thread_id, temp);
        shared_counter = temp + 1;
        usleep(100000);  // Simulate work
        
        // Signal (V operation) - release semaphore
        sem_post(&mutex);
        
        // Non-critical section
        usleep(50000);
    }
    
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];
    
    // Initialize semaphore (binary = 1)
    if (sem_init(&mutex, 0, 1) == -1) {
        perror("sem_init failed");
        exit(1);
    }
    
    printf("Starting %d threads with mutual exclusion...\n", NUM_THREADS);
    printf("Target counter: %d\n\n", SHARED_RESOURCE);
    
    // Create threads
    for(int i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i;
        if(pthread_create(&threads[i], NULL, thread_function, &thread_ids[i]) != 0) {
            perror("pthread_create failed");
            exit(1);
        }
    }
    
    // Wait for all threads to complete
    for(int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    
    printf("\nFinal counter value: %d (correct!)\n", shared_counter);
    
    // Cleanup semaphore
    sem_destroy(&mutex);
    
    return 0;
}
