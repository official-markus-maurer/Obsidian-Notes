# Structs and Data Access (Assembly)

In C, a `struct` is a composite type. In assembly, it's just a block of memory. The compiler calculates **offsets** for each member based on their size and alignment.

## 📏 Calculating Offsets

Consider this C struct:
```c
struct Point {
    int x;      // Offset 0, Size 4
    int y;      // Offset 4, Size 4
    char name;  // Offset 8, Size 1
    // Padding: 3 bytes (to align next struct to 4 bytes)
};
```

If `RBX` points to the start of a `struct Point`:
-   `x` is at `[RBX + 0]`
-   `y` is at `[RBX + 4]`
-   `name` is at `[RBX + 8]`

### Assembly Example

```asm
; Assume RDI points to struct Point
mov eax, [rdi]      ; Read x
mov ecx, [rdi + 4]  ; Read y
mov dl,  [rdi + 8]  ; Read name (1 byte)
```

## 📦 Arrays of Structs

Accessing `points[i].y`:
Address = `Base + (Index * StructSize) + Offset`

If `sizeof(struct Point)` is 12 bytes (due to padding):
```asm
; RDI = Base address of array
; RSI = Index 'i'

imul rsi, rsi, 12   ; RSI = i * 12
mov eax, [rdi + rsi + 4] ; Read points[i].y
```
*Note: We can't use standard scaled indexing (`[base + index*scale]`) because 12 is not a valid scale (only 1, 2, 4, 8).*

## 🏗️ Alignment and Padding

The compiler inserts padding to ensure members are aligned naturally (int on 4-byte boundary, double on 8-byte).

```c
struct Mixed {
    char a;     // 1 byte
    // 3 bytes padding
    int b;      // 4 bytes
    short c;    // 2 bytes
    // 6 bytes padding (to align struct to 8 bytes if it contains 64-bit members elsewhere?)
    // Actually, usually padded to largest member size.
};
```

**Assembly View**:
-   `a`: `[base]`
-   `b`: `[base + 4]` (Skipped 3 bytes!)
-   `c`: `[base + 8]`

## 🛠️ Exploring with `offsetof`

You can verify offsets in C using `stddef.h`:

```c
#include <stddef.h>
#include <stdio.h>

struct Data {
    char c;
    double d;
};

int main() {
    printf("Offset of d: %zu\n", offsetof(struct Data, d));
    // Output: 8 (usually), because double needs 8-byte alignment
    return 0;
}
```

---
[[00-Index|Back to Assembly Index]]
