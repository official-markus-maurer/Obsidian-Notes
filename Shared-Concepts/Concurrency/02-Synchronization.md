# Synchronization

When multiple threads access shared memory, **Race Conditions** can occur. Synchronization primitives prevent this.

## Mutex (Mutual Exclusion)
A lock that allows only one thread to access a critical section at a time.
-   **Lock**: Enter critical section.
-   **Unlock**: Exit critical section.

## Semaphore
A counter that controls access to a common resource by multiple threads.
-   **Wait (P)**: Decrement counter. If 0, block.
-   **Signal (V)**: Increment counter. Wake up a blocked thread.

## Atomic Operations
Hardware instructions that complete in a single step, preventing interruption.
-   `atomic_fetch_add`
-   `atomic_compare_exchange`

---
[[00-Index|Back to Concurrency Index]]
