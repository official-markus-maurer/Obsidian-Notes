# Memory Alignment and Padding

When you define a structure, the compiler might add extra bytes (padding) between members to align them on memory boundaries. This is done for performance reasons.

## 🧱 What is Alignment?
Processors read memory in chunks (words), typically 4 or 8 bytes. Accessing data that straddles these boundaries is slower or even crashes on some architectures (like ARM).

-   **Char**: 1-byte aligned (any address).
-   **Short**: 2-byte aligned (address must be even).
-   **Int/Float**: 4-byte aligned (address must be divisible by 4).
-   **Double/Long**: 8-byte aligned.

## 📏 Padding Example

```c
struct Example {
    char c;     // 1 byte
    int i;      // 4 bytes
};
```
You might expect `sizeof(struct Example)` to be 5 bytes. But it's often **8 bytes**.

**Layout:**
```
| 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
| c | P | P | P | i | i | i | i |
```
-   `c` takes 1 byte.
-   3 bytes of **Padding** (`P`) are added so `i` starts at offset 4 (divisible by 4).

## 📉 Optimizing Layout (Member Reordering)
You can reduce padding by ordering members from largest to smallest.

**Bad Layout (12 bytes):**
```c
struct Bad {
    char c;     // 1 byte + 3 padding
    int i;      // 4 bytes
    char d;     // 1 byte + 3 padding
};
```

**Good Layout (8 bytes):**
```c
struct Good {
    int i;      // 4 bytes
    char c;     // 1 byte
    char d;     // 1 byte
    // 2 bytes trailing padding (to align struct size to 4)
};
```

## 📦 Structure Packing

Sometimes you want to avoid padding (e.g., for network packets or binary file formats). You can use compiler attributes.

```c
// GCC / Clang
struct __attribute__((packed)) PackedExample {
    char c;
    int i;
};
// sizeof is now 5 bytes
```
> **Warning**: Packed structures are slower to access and may cause crashes on some CPUs if accessed directly. Always copy packed data to aligned variables before processing.

## 🤏 Bit Fields

Bit fields allow you to specify the exact number of bits a member should occupy. Useful for flags or hardware registers.

```c
struct Flags {
    unsigned int is_active : 1;  // 1 bit
    unsigned int has_error : 1;  // 1 bit
    unsigned int mode : 2;       // 2 bits (values 0-3)
};
```
Total size will be rounded up to the nearest integer size (usually 4 bytes).

---
[[00-Index|Back to Structs Index]]
