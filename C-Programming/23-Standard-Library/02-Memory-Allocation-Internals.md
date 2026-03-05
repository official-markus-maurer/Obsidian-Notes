# Malloc Internals

`malloc` is not a system call. It is a user-space library function that manages a large block of memory obtained from the OS.

## 🏗️ Getting Memory from OS

The allocator (like `ptmalloc` in glibc) requests large chunks of memory using two main mechanisms:

1.  **`sbrk` (System Break)**: Increases the "program break" (end of the heap).
    -   Legacy method, simple but limited (must be contiguous).
    -   `sbrk(0)` returns current break. `sbrk(size)` increases it.
2.  **`mmap` (Memory Map)**: Maps new pages of memory.
    -   Used for large allocations (>128KB usually).
    -   More flexible, allows returning memory to OS (`munmap`).

## 📝 Heap Structure (The Free List)

The heap is usually organized as a linked list of **chunks**. Each chunk has a header hidden *before* the pointer returned to you.

```c
struct ChunkHeader {
    size_t size;   // Size of block (including header)
    int is_free;   // 1 if free, 0 if used
    struct ChunkHeader *next;
    struct ChunkHeader *prev;
};
```

When you call `malloc(size)`:
1.  Search the free list for a chunk >= `size`.
2.  Split it if too large (return unused part to free list).
3.  Mark as used.
4.  Return pointer to payload (after header).

When you call `free(ptr)`:
1.  Read header at `ptr - sizeof(Header)`.
2.  Mark as free.
3.  **Coalesce**: Check if adjacent chunks are free and merge them into one larger chunk.

## 🧩 Fragmentation
-   **External Fragmentation**: Free blocks exist but are too small to satisfy a request (Swiss cheese effect).
-   **Internal Fragmentation**: Allocated block is slightly larger than requested (due to alignment or minimum chunk size).

## 🛡️ Heap Exploitation (Introduction)
If you overflow a buffer on the heap, you overwrite the *next chunk's header*.
-   **House of Force**: Overwrite `top_chunk` size to allocate huge memory.
-   **Double Free**: Freeing the same pointer twice corrupts the free list (linked list cycle).
-   **Use After Free**: Accessing freed memory that has been reallocated for something else.

---
[[00-Index|Back to Stdlib Index]]
