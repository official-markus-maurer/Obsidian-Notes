# Bit Manipulation

C allows you to manipulate data at the bit level. This is useful for low-level programming, embedded systems, and optimizing storage.

## 🔢 Bitwise Operators

| Operator | Name | Description | Example (A=60, B=13) |
|---|---|---|---|
| `&` | AND | Both bits must be 1 | `A & B = 12` (0000 1100) |
| `\|` | OR | Either bit is 1 | `A \| B = 61` (0011 1101) |
| `^` | XOR | Bits must be different | `A ^ B = 49` (0011 0001) |
| `~` | NOT | Flips all bits (0->1, 1->0) | `~A = -61` (1100 0011) |
| `<<` | Left Shift | Shifts bits left (multiply by 2^n) | `A << 2 = 240` |
| `>>` | Right Shift | Shifts bits right (divide by 2^n) | `A >> 2 = 15` |

## 🎭 Common Idioms (Bit Masks)

Assume `n` is the bit index (0 to 31).

### Set a Bit
Turns the nth bit to 1.
```c
num |= (1 << n);
```

### Clear a Bit
Turns the nth bit to 0.
```c
num &= ~(1 << n);
```

### Toggle a Bit
Flips the nth bit (0->1, 1->0).
```c
num ^= (1 << n);
```

### Check a Bit
Returns non-zero if the nth bit is 1.
```c
if (num & (1 << n)) { ... }
```

### Extracting a Bit Field
To get bits 4-7 from a value:
```c
// 1. Create mask: 0000 1111 (0xF)
// 2. Shift value right by 4
// 3. AND with mask
unsigned int val = (reg >> 4) & 0xF;
```

## 🏗️ Bit Fields (Structs)

C allows you to define struct members with specific bit widths.

```c
struct Flags {
    unsigned int is_visible : 1;  // 1 bit
    unsigned int is_active  : 1;  // 1 bit
    unsigned int priority   : 3;  // 3 bits (0-7)
    unsigned int reserved   : 27; // Padding
};
```
*Warning: The ordering of bit fields is implementation-defined (endianness matters).*

## 🧠 Clever Tricks

### Is Power of 2?
A power of 2 has exactly one bit set (e.g., 8 is `1000`). `x-1` flips all bits up to that set bit (e.g., 7 is `0111`).
```c
bool isPowerOfTwo(unsigned int x) {
    return (x != 0) && ((x & (x - 1)) == 0);
}
```

### Swap Variables (No Temp)
Using XOR properties (`x^x=0`, `x^0=x`).
```c
a ^= b;
b ^= a;
a ^= b;
```
*Note: This is mostly a party trick. Compilers optimize temporary variables better.*

---
[[00-Index|Back to Advanced Index]]
