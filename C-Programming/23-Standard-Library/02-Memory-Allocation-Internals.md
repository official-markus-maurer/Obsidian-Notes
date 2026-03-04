# Malloc Internals

`malloc` is not a system call. It is a user-space library function that manages a large block of memory obtained from the OS.

## 🏗️ Getting Memory from OS

1.  **`sbrk`**: Increases the "program break" (end of the heap). Legacy method.
2.  **`mmap`**: Maps new pages of memory. Used for large allocations.

## 📝 Heap Structure

The heap is usually organized as a list of "chunks". Each chunk has a header.

```c
struct ChunkHeader {
    size_t size;   // Size of block
    int is_free;   // 1 if free, 0 if used
    struct ChunkHeader *next;
};
```

When you call `free(ptr)`, the library doesn't necessarily return memory to the OS. It marks the chunk as "free" so it can be reused by a future `malloc`.

## 🧩 Fragmentation
-   **External Fragmentation**: Free blocks exist but are too small to satisfy a request.
-   **Internal Fragmentation**: Allocated block is slightly larger than requested (due to alignment).

---
[[00-Index|Back to Stdlib Index]]
