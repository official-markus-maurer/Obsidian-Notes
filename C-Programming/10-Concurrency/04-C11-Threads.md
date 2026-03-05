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

## ⚛️ Atomic Operations (`<stdatomic.h>`)

C11 introduces a standard way to perform atomic operations without locks. This maps directly to assembly instructions like `LOCK XADD` or `LOCK CMPXCHG`.

### Key Types
-   `atomic_int`, `atomic_long`, `atomic_bool`, etc.
-   `_Atomic(T)`: Generic wrapper.

### Memory Ordering (`memory_order`)
This is crucial for understanding how instructions are reordered by the CPU/Compiler.

1.  `memory_order_relaxed`: No synchronization. Just atomicity.
    -   *Assembly*: Just the instruction (e.g., `INC`).
2.  `memory_order_acquire`: Acquire fence (Read).
    -   *Assembly*: Ensures no reads move before this instruction.
3.  `memory_order_release`: Release fence (Write).
    -   *Assembly*: Ensures no writes move after this instruction.
4.  `memory_order_seq_cst`: Sequentially Consistent (Default).
    -   *Assembly*: Strongest fence (`MFENCE` or `LOCK` prefix). Prevents all reordering.

```c
#include <stdatomic.h>

atomic_int counter = 0;

void increment() {
    // Equivalent to: LOCK INC [counter]
    atomic_fetch_add(&counter, 1);
}

int load() {
    // Equivalent to: MOV EAX, [counter] (with fencing)
    return atomic_load(&counter);
}
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
