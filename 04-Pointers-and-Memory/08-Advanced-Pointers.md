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

3.  **Constant Pointer to Constant** (`const int * const`):
    -   Neither the data nor the pointer can be changed.
    ```c
    const int * const ptr = &var;
    ```

---
[[00-Index|Back to Pointers Index]]
