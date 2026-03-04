# System Programming

System programming involves writing software that provides services to the computer hardware or other software. In C, this often means interacting directly with the Operating System kernel via **System Calls**.

## 📋 Topics

1.  **[[../../Shared-Concepts/Operating-Systems/02-System-Calls|System Calls (Theory)]]**
    -   Kernel Mode vs User Mode (moved to Shared Concepts).

2.  **[[01-System-Calls-IO|File I/O Syscalls]]**
    -   `open`, `read`, `write`, `close`
    -   File Descriptors vs `FILE*`

3.  **[[../../Shared-Concepts/Concurrency/01-Processes-vs-Threads|Processes (Theory)]]**
    -   Concept of a Process (moved to Shared Concepts).

4.  **[[02-Processes-and-Fork|Forking & Exec]]**
    -   Creating processes with `fork()`
    -   `exec` family

5.  **[[../../Shared-Concepts/Operating-Systems/04-Signals|Signals (Theory)]]**
    -   Interrupts and Handling (moved to Shared Concepts).

6.  **[[03-Signals|Handling Signals in C]]**
    -   `signal()` and `sigaction()`

7.  **[[04-IPC-Pipes|IPC: Pipes & FIFOs]]**
    -   Unnamed Pipes (`pipe`)
    -   Named Pipes (FIFOs)

5.  **[[05-Shared-Memory|IPC: Shared Memory]]**
    -   `shm_open`, `mmap`
    -   Fastest IPC method

---
**Next Section**: [[../16-Optimization/00-Index|Optimization]]
