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

### 💀 Deadlock
Occurs when two threads are waiting for each other to release a lock.
-   Thread A holds Lock 1, waits for Lock 2.
-   Thread B holds Lock 2, waits for Lock 1.
-   **Result**: Program freezes forever.

**Prevention**: Always acquire locks in the same order.

---
[[00-Index|Back to Concurrency Index]]
