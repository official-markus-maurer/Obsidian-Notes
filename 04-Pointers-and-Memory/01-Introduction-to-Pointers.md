# Introduction to Pointers

A pointer is a variable that stores the memory address of another variable.

## 📍 Key Operators

1. **Address-of Operator (`&`)**: Returns the memory address of a variable.
2. **Dereference Operator (`*`)**: Accesses the value stored at the memory address held by the pointer.

## 📝 Syntax

```c
int *ptr; // Declaration: ptr is a pointer to an int
int var = 10;

ptr = &var; // Initialization: ptr holds the address of var
```

## 🧩 Example

```c
#include <stdio.h>

int main() {
    int num = 42;
    int *ptr = &num;

    printf("Value of num: %d\n", num);
    printf("Address of num: %p\n", &num);
    printf("Value of ptr: %p\n", ptr);
    printf("Value pointed to by ptr: %d\n", *ptr); // Dereferencing

    *ptr = 100; // Changing value through pointer
    printf("New value of num: %d\n", num);

    return 0;
}
```

## ⚠️ Common Mistakes
- **Uninitialized Pointers**: Using a pointer without initializing it can lead to crashes (segmentation faults).
- **Null Pointers**: Always check if a pointer is `NULL` before dereferencing it if there's a chance it might be invalid.

```c
int *ptr = NULL;
// ... later ...
if (ptr != NULL) {
    // Safe to use ptr
}
```

---
[[00-Index|Back to Pointers Index]]
