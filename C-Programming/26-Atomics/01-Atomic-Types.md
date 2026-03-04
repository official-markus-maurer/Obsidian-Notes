# Atomic Types

An atomic operation is indivisible. No other thread can see the operation "half-done".

## ⚛️ Syntax

```c
#include <stdatomic.h>
#include <stdio.h>
#include <threads.h>

atomic_int counter = 0; // or _Atomic int counter;

int worker(void *arg) {
    for (int i = 0; i < 10000; i++) {
        // Atomic increment. No mutex needed!
        counter++; 
        // Equivalent to: atomic_fetch_add(&counter, 1);
    }
    return 0;
}

int main() {
    thrd_t t1, t2;
    thrd_create(&t1, worker, NULL);
    thrd_create(&t2, worker, NULL);
    thrd_join(t1, NULL);
    thrd_join(t2, NULL);
    
    printf("Counter: %d\n", counter); // Guaranteed 20000
    return 0;
}
```

## 🚩 `atomic_flag`
The only type guaranteed to be lock-free on all platforms. Used to implement spinlocks.

```c
atomic_flag lock = ATOMIC_FLAG_INIT;

void spin_lock() {
    while (atomic_flag_test_and_set(&lock)) {
        // Spin wait
    }
}

void spin_unlock() {
    atomic_flag_clear(&lock);
}
```

---
[[00-Index|Back to Atomics Index]]
