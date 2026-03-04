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

void* myThreadFunc(void* arg) {
    printf("Hello from thread!\n");
    return NULL;
}

int main() {
    pthread_t thread_id;
    
    // Create thread
    // &id, attributes (NULL), function, argument (NULL)
    pthread_create(&thread_id, NULL, myThreadFunc, NULL);
    
    // Wait for thread to finish
    pthread_join(thread_id, NULL);
    
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

---
[[00-Index|Back to Concurrency Index]]
