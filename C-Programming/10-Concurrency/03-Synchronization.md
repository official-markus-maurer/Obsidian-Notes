# Synchronization

When multiple threads access shared resources, you must synchronize them to prevent race conditions.

## 🔒 Mutex (Mutual Exclusion)

A Mutex acts like a lock. Only one thread can hold the lock at a time.

### Functions
-   `pthread_mutex_init`: Initialize the lock.
-   `pthread_mutex_lock`: Acquire the lock (blocks if already locked).
-   `pthread_mutex_unlock`: Release the lock.
-   `pthread_mutex_destroy`: Clean up.

### Example: Thread-Safe Counter

```c
#include <stdio.h>
#include <pthread.h>

int counter = 0;
pthread_mutex_t lock; // Declare mutex

void* increment(void* arg) {
    for (int i = 0; i < 1000000; i++) {
        pthread_mutex_lock(&lock);   // 🔒 Lock
        counter++;                   // Critical Section
        pthread_mutex_unlock(&lock); // 🔓 Unlock
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;
    pthread_mutex_init(&lock, NULL); // Initialize
    
    pthread_create(&t1, NULL, increment, NULL);
    pthread_create(&t2, NULL, increment, NULL);
    
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    
    printf("Final Counter: %d\n", counter); // Should be 2000000
    
    pthread_mutex_destroy(&lock); // Cleanup
    return 0;
}
```

## 🚥 Condition Variables

Condition variables allow threads to wait until a certain condition is true. They are always used with a mutex.

### Functions
-   `pthread_cond_wait`: Sleep until signaled. Releases the mutex while sleeping and re-acquires it when waking up.
-   `pthread_cond_signal`: Wake up one waiting thread.
-   `pthread_cond_broadcast`: Wake up all waiting threads.

### Example: Producer-Consumer

```c
pthread_mutex_t lock;
pthread_cond_t cond;
int ready = 0;

void* producer(void* arg) {
    pthread_mutex_lock(&lock);
    ready = 1; // Produce
    printf("Producer: Data ready.\n");
    pthread_cond_signal(&cond); // Signal consumer
    pthread_mutex_unlock(&lock);
    return NULL;
}

void* consumer(void* arg) {
    pthread_mutex_lock(&lock);
    while (ready == 0) {
        printf("Consumer: Waiting...\n");
        pthread_cond_wait(&cond, &lock); // Wait (releases lock)
    }
    printf("Consumer: Data received!\n");
    pthread_mutex_unlock(&lock);
    return NULL;
}
```

### 💀 Deadlock
Occurs when two threads are waiting for each other to release a lock.
-   Thread A holds Lock 1, waits for Lock 2.
-   Thread B holds Lock 2, waits for Lock 1.
-   **Result**: Program freezes forever.

**Prevention**: Always acquire locks in the same order.

---
[[00-Index|Back to Concurrency Index]]
