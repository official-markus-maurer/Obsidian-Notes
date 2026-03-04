# Introduction to Threads

## 🧵 Process vs. Thread

### Process
-   An instance of a running program.
-   Has its own independent memory space (Heap, Data, etc.).
-   Heavyweight: Creating a process is slow.
-   Communication between processes (IPC) is complex (pipes, sockets, shared memory).

### Thread
-   A unit of execution within a process.
-   **Shares memory** (Heap, Data, Code) with other threads in the same process.
-   Has its own **Stack** and **Registers**.
-   Lightweight: Creating a thread is fast.
-   Communication is easy (shared variables), but requires **synchronization**.

## 🚀 Why Multithreading?
1.  **Performance**: Utilize multi-core CPUs.
2.  **Responsiveness**: Keep the UI responsive while doing background work.
3.  **Efficiency**: Handle I/O operations without blocking the main program.

## ⚠️ The Danger: Race Conditions
Since threads share memory, if two threads try to modify the same variable at the same time, the result is unpredictable. This is called a **Race Condition**.

---
[[00-Index|Back to Concurrency Index]]
