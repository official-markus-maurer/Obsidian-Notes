# Deadlocks

A deadlock is a situation where two or more threads are blocked forever, waiting for each other.

## Necessary Conditions (Coffman Conditions)
1.  **Mutual Exclusion**: Resources cannot be shared.
2.  **Hold and Wait**: A process holding a resource is waiting for another.
3.  **No Preemption**: Resources cannot be forcibly taken.
4.  **Circular Wait**: A -> B -> C -> A.

## Prevention
-   **Lock Ordering**: Always acquire locks in a consistent global order.
-   **Timeouts**: Give up if a lock cannot be acquired within X ms.
-   **Deadlock Detection**: Algorithms to find cycles in the resource allocation graph.

---
[[00-Index|Back to Concurrency Index]]
