# Pointer Arithmetic

Pointers can be incremented, decremented, added to, and subtracted from. However, these operations depend on the data type the pointer points to.

## ➕ Incrementing Pointers
When you increment a pointer (`ptr++`), it points to the next memory location of its type.
- If `ptr` is `int*` (4 bytes), `ptr++` adds 4 to the address.
- If `ptr` is `char*` (1 byte), `ptr++` adds 1 to the address.

## ➖ Decrementing Pointers
Similarly, decrementing (`ptr--`) moves the pointer back by the size of the data type.

## 🧮 Example

```c
#include <stdio.h>

int main() {
    int arr[] = {10, 20, 30};
    int *ptr = arr; // Points to arr[0]

    printf("Value: %d, Address: %p\n", *ptr, ptr);

    ptr++; // Move to next int
    printf("Value: %d, Address: %p\n", *ptr, ptr);

    ptr++; // Move to next int
    printf("Value: %d, Address: %p\n", *ptr, ptr);

    return 0;
}
```

## 📏 Pointer Subtraction
Subtracting two pointers (of the same type) returns the number of elements between them.

```c
int *p1 = &arr[0];
int *p2 = &arr[2];
printf("Difference: %ld\n", p2 - p1); // Output: 2
```

---
[[00-Index|Back to Pointers Index]]
