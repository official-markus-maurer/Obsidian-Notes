# Typedef

The `typedef` keyword is used to give a type a new name.

## 🏷️ Basic Usage

```c
typedef unsigned char BYTE;

BYTE b1, b2; // Same as unsigned char b1, b2;
```

## 🏗️ With Structures

`typedef` is commonly used with structures to avoid writing `struct` every time.

```c
typedef struct {
    char title[50];
    char author[50];
    int id;
} Book;

Book book1; // No need to write 'struct Book book1;'
```

This creates a cleaner syntax and abstracts the underlying implementation details.

---
[[00-Index|Back to Structs Index]]
