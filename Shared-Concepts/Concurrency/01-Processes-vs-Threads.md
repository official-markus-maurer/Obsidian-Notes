# Processes vs Threads

## Process
A process is an instance of a computer program that is being executed.
-   **Isolation**: Each process has its own virtual memory space.
-   **Communication**: Requires IPC (Inter-Process Communication) like pipes, sockets, or shared memory.
-   **Overhead**: Creating a process is heavy (OS must allocate memory tables).

## Thread
A thread is a lightweight unit of execution within a process.
-   **Sharing**: All threads share the same heap and global variables.
-   **Communication**: Direct (reading/writing shared variables).
-   **Overhead**: Creating a thread is light.
-   **Risk**: Race conditions due to shared memory.

## Comparison Table
| Feature | Process | Thread |
| :--- | :--- | :--- |
| **Memory** | Isolated | Shared |
| **Creation** | Heavy | Light |
| **Safety** | High (Crash doesn't kill others) | Low (Crash kills process) |

---
[[00-Index|Back to Concurrency Index]]
