# Memory Ordering

By default, atomics use **Sequential Consistency** (`memory_order_seq_cst`), which is safe but slow (prevents compiler/CPU reordering). You can use weaker orderings for speed.

## 🚦 Orderings

1.  **`memory_order_relaxed`**: No synchronization. Only guarantees atomicity of the operation itself.
2.  **`memory_order_acquire`**: Read operation. Ensures subsequent reads/writes happen *after* this load.
3.  **`memory_order_release`**: Write operation. Ensures previous reads/writes happen *before* this store.
4.  **`memory_order_acq_rel`**: Read-Modify-Write.
5.  **`memory_order_seq_cst`**: Full global ordering.

## 🛠️ Example: Release-Acquire

Used for passing data between threads without a full lock.

```c
atomic_int data_ready = 0;
int payload = 0;

void producer() {
    payload = 42;
    // Release: Ensure payload write is visible before setting flag
    atomic_store_explicit(&data_ready, 1, memory_order_release);
}

void consumer() {
    // Acquire: Ensure we see payload write if we see flag set
    while (atomic_load_explicit(&data_ready, memory_order_acquire) == 0);
    printf("Payload: %d\n", payload); // Safe
}
```

---
[[00-Index|Back to Atomics Index]]
