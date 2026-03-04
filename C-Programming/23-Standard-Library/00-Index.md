# C Standard Library Deep Dive

Understanding what happens "under the hood" of standard library functions helps you write better code.

## 📋 Topics

1.  **[[01-Stdio-Internals|Stdio Internals]]**
    -   Buffering mechanism (`FILE` struct)
    -   `printf` implementation

2.  **[[02-Memory-Allocation-Internals|Malloc Internals]]**
    -   How `malloc` works (sbrk, mmap)
    -   Free lists

3.  **[[03-String-Functions|String Optimization]]**
    -   How `strlen` and `memcpy` are optimized

---
**Next Section**: [[../24-Garbage-Collection/00-Index|Garbage Collection]]
