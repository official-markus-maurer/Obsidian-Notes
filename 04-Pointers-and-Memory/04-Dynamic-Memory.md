# Dynamic Memory Allocation

Static memory allocation (like `int arr[10];`) has a fixed size at compile time. Dynamic memory allocation allows you to allocate memory at runtime using functions from `<stdlib.h>`.

## 🛠️ Functions

### 1. `malloc` (Memory Allocation)
Allocates a block of memory of specified size (in bytes). Returns a `void*` pointer to the first byte. The memory is uninitialized (contains garbage values).

```c
int *ptr = (int*) malloc(5 * sizeof(int)); // Allocates space for 5 integers
```

### 2. `calloc` (Contiguous Allocation)
Allocates memory for an array of elements, initializes them to zero.

```c
int *ptr = (int*) calloc(5, sizeof(int)); // Allocates space for 5 integers, all 0
```

### 3. `realloc` (Re-allocation)
Changes the size of previously allocated memory.

```c
ptr = (int*) realloc(ptr, 10 * sizeof(int)); // Resizes to hold 10 integers
```

### 4. `free` (Free Memory)
Deallocates the memory previously allocated by `malloc`, `calloc`, or `realloc`. This is crucial to prevent memory leaks.

```c
free(ptr);
ptr = NULL; // Good practice to prevent dangling pointers
```

## ⚠️ Memory Leaks
A memory leak occurs when you allocate memory but forget to free it. The memory remains occupied until the program terminates, which can exhaust system resources in long-running programs.

---
[[00-Index|Back to Pointers Index]]
