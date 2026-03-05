# Advanced Pointer Concepts

This section covers more complex uses of pointers that are essential for real-world C programming.

## 👥 Double Pointers (Pointer to Pointer)

A pointer to a pointer is a form of multiple indirection, or a chain of pointers.

```c
int var = 3000;
int *ptr = &var;
int **pptr = &ptr;
```

### Why use them?
1.  **Modifying a pointer in a function**: If you want a function to change where a pointer points (e.g., allocating memory inside a function), you must pass the address of the pointer.
    ```c
    void allocate(int **p) {
        *p = malloc(sizeof(int));
    }
    
    int *ptr = NULL;
    allocate(&ptr); // Pass address of ptr
    ```
2.  **2D Arrays**: Dynamically allocated 2D arrays are often `int**`.

## 🕳️ Void Pointers (`void *`)

A `void *` is a generic pointer type. It can point to objects of any data type.

-   **Pros**: Useful for generic functions (like `malloc`, `qsort`, `memcpy`).
-   **Cons**: You **cannot dereference** a void pointer directly. You must cast it to another type first.
-   **Arithmetic**: Pointer arithmetic on `void*` is not allowed in standard C (though GCC allows it as an extension, treating size as 1 byte).

```c
int a = 10;
void *ptr = &a;
printf("%d", *(int*)ptr); // Must cast to int* before dereferencing
```

## 🔒 Const Correctness

Using `const` with pointers can be tricky. Read declarations from right to left.

1.  **Pointer to Constant** (`const int *` or `int const *`):
    -   The *data* is constant. You cannot change the value pointed to.
    -   You *can* change the pointer to point elsewhere.
    ```c
    const int *ptr = &var;
    *ptr = 10; // Error!
    ptr = &var2; // OK
    ```

2.  **Constant Pointer** (`int * const`):
    -   The *pointer* is constant. You cannot change where it points.
    -   You *can* change the data.
    ```c
    int * const ptr = &var;
    *ptr = 10; // OK
    ptr = &var2; // Error!
    ```

## 🚫 The `restrict` Keyword (C99)

`restrict` tells the compiler that a pointer is the **only** way to access the object it points to. This allows aggressive optimizations.

```c
void add_arrays(int *restrict a, int *restrict b, int *restrict c, int n) {
    for (int i = 0; i < n; i++) {
        a[i] = b[i] + c[i];
    }
}
```
Here, the compiler assumes `a`, `b`, and `c` do not overlap (alias). It can vectorize the loop freely.
Without `restrict`, if `a == b`, writing to `a[i]` might change `b[i+1]`, forcing the compiler to reload `b` every iteration.

## ⚠️ Strict Aliasing Rule

Standard C says pointers of incompatible types cannot alias the same memory location (except `char*`).

```c
float f = 3.14;
int *i = (int*)&f; // ⚠️ Undefined Behavior (Strict Aliasing Violation)
printf("%d\n", *i);
```
The compiler assumes `int*` and `float*` point to different memory. It might reorder reads/writes, causing bugs.
**Solution**: Use `memcpy` or a `union` for type punning.

---
[[00-Index|Back to Pointers Index]]
