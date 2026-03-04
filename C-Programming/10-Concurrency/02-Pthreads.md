# POSIX Threads (Pthreads)

Pthreads is the standard API for threading in C on Unix-like systems (Linux, macOS). On Windows, you might need a compatibility layer or use the native Windows API (though C11 introduced `<threads.h>` which is becoming more common).

## 📚 Header and Compilation

Include `<pthread.h>` and link with `-pthread`.

```bash
gcc main.c -o main -pthread
```

## 🛠️ Basic Usage

### 1. Creating a Thread (`pthread_create`)

```c
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void* myThreadFunc(void* arg) {
    printf("Hello from thread!\n");
    return NULL;
}

int main() {
    pthread_t thread_id;
    
    // Create thread
    // &id, attributes (NULL), function, argument (NULL)
    if (pthread_create(&thread_id, NULL, myThreadFunc, NULL) != 0) {
        perror("Thread creation failed");
        return 1;
    }
    
    // Wait for thread to finish
    if (pthread_join(thread_id, NULL) != 0) {
        perror("Thread join failed");
        return 1;
    }
    
    printf("Thread finished.\n");
    return 0;
}
```

### 2. Passing Arguments

You can pass a single `void*` argument. To pass multiple values, use a struct.

```c
struct Args {
    int id;
    int value;
};

void* worker(void* arg) {
    struct Args* data = (struct Args*)arg;
    printf("ID: %d, Value: %d\n", data->id, data->value);
    // Don't free arg here if it's on stack in main!
    return NULL;
}

int main() {
    pthread_t t;
    struct Args args = {1, 100};
    
    pthread_create(&t, NULL, worker, &args);
    pthread_join(t, NULL);
    return 0;
}
```

## 🔒 Synchronization

### Mutex (Mutual Exclusion)
Protect shared data from race conditions.

```c
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int counter = 0;

void* count(void* arg) {
    for (int i = 0; i < 10000; i++) {
        pthread_mutex_lock(&mutex);
        counter++;
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}
```

### Condition Variables
Wait for a condition to be true (e.g., queue not empty).

```c
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
int ready = 0;

void* consumer(void* arg) {
    pthread_mutex_lock(&lock);
    while (ready == 0) {
        // Releases lock and waits. Re-acquires lock when signaled.
        pthread_cond_wait(&cond, &lock);
    }
    // Do work...
    pthread_mutex_unlock(&lock);
    return NULL;
}

void* producer(void* arg) {
    pthread_mutex_lock(&lock);
    ready = 1;
    pthread_cond_signal(&cond); // Wake up waiting thread
    pthread_mutex_unlock(&lock);
    return NULL;
}
```

## ⚠️ Common Pitfalls
1.  **Race Conditions**: Accessing shared data without a lock.
2.  **Deadlocks**: Waiting for a lock that is held by another thread waiting for you.
3.  **False Sharing**: Multiple threads updating variables on the same cache line.

---
[[00-Index|Back to Concurrency Index]]
