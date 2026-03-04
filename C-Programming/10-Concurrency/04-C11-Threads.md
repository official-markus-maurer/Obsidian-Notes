# C11 Threads (`<threads.h>`)

Introduced in C11, this is an optional standard library for threading. It is more portable than Pthreads (which is POSIX-only) but less feature-rich.

## 📦 Key Types
-   `thrd_t`: Thread identifier.
-   `mtx_t`: Mutex.
-   `cnd_t`: Condition variable.
-   `thrd_start_t`: Function pointer type for thread entry (`int (*)(void*)`).

## 🚀 Creating a Thread
```c
#include <threads.h>
#include <stdio.h>

int run(void *arg) {
    printf("Thread running with arg: %d\n", *(int*)arg);
    return 0;
}

int main() {
    thrd_t t;
    int arg = 42;
    
    if (thrd_create(&t, run, &arg) == thrd_success) {
        thrd_join(t, NULL);
    }
    return 0;
}
```

## 🔒 Mutexes
```c
mtx_t mutex;
mtx_init(&mutex, mtx_plain);

mtx_lock(&mutex);
// Critical Section
mtx_unlock(&mutex);

mtx_destroy(&mutex);
```

## 🆚 C11 Threads vs Pthreads
| Feature | C11 Threads | Pthreads |
| :--- | :--- | :--- |
| **Portability** | Standard C (Windows/Linux) | POSIX (Linux/macOS) |
| **Return Type** | `int` | `void*` |
| **Detach** | `thrd_detach` | `pthread_detach` |
| **Complexity** | Simple | Complex (Attributes) |

---
[[00-Index|Back to Concurrency Index]]
