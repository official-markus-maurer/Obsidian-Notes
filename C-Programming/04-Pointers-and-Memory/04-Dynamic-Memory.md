# Dynamic Memory Allocation

Static memory allocation (like `int arr[10];`) has a fixed size at compile time. Dynamic memory allocation allows you to allocate memory at runtime using functions from `<stdlib.h>`.

## 🛠️ Functions

### 1. `malloc` (Memory Allocation)
Allocates a block of memory of specified size (in bytes). Returns a `void*` pointer to the first byte. The memory is uninitialized (contains garbage values).

```c
// Note: In C, you don't need to cast void*. It's implicitly converted.
int *ptr = malloc(5 * sizeof(int)); 
if (ptr == NULL) { /* Handle error */ }
```

### 2. `calloc` (Contiguous Allocation)
Allocates memory for an array of elements, initializes them to **zero**. Safer than malloc for initialization.

```c
int *ptr = calloc(5, sizeof(int)); // 5 integers, all 0
```

### 3. `realloc` (Re-allocation)
Changes the size of previously allocated memory.
-   If larger, new space is uninitialized.
-   If smaller, data is truncated.
-   If it fails, it returns `NULL` but **leaves the original block untouched**.

```c
int *new_ptr = realloc(ptr, 10 * sizeof(int));
if (new_ptr != NULL) {
    ptr = new_ptr;
} else {
    // Allocation failed, ptr is still valid
}
```

### 4. `free` (Free Memory)
Deallocates the memory. Passing `NULL` to `free` is safe (it does nothing).

```c
free(ptr);
ptr = NULL; // Good practice to prevent double-free
```

## 📜 C11: Aligned Allocation
Sometimes hardware (SIMD, Cache lines) requires memory to be aligned to specific boundaries (e.g., 64 bytes).

```c
#include <stdlib.h>
// Size must be a multiple of alignment
void *p = aligned_alloc(64, 1024); 
free(p);
```

## ⚠️ Common Pitfalls
1.  **Memory Leaks**: Forgetting to `free()`.
2.  **Double Free**: Calling `free()` twice on the same pointer.
3.  **Dangling Pointer**: Using a pointer after `free()`.
4.  **Fragmentation**: Frequent alloc/free can fragment the heap.

---
[[00-Index|Back to Pointers Index]]
