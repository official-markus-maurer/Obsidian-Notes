# Bit Manipulation (Assembly)

C has `<<`, `>>`, `&`, `|`, `^`. Assembly offers more precise control.

## 🔀 Shifts

### Logical Shift (Unsigned)
Fills the vacant bits with **0**.

-   **`SHL` (Shift Left)**: `x << n`. Equivalent to multiplying by $2^n$.
-   **`SHR` (Shift Right)**: `x >> n`. Equivalent to dividing by $2^n$ (unsigned).

### Arithmetic Shift (Signed)
-   **`SAL` (Shift Arithmetic Left)**: Same as `SHL`.
-   **`SAR` (Shift Arithmetic Right)**: `x >> n`. Fills with the **Sign Bit** (preserves negative numbers).

```asm
mov al, -8      ; AL = 0xF8 (1111 1000)
sar al, 1       ; AL = 0xFC (1111 1100) -> -4
shr al, 1       ; AL = 0x7C (0111 1100) -> 124 (Positive!)
```

## 🔄 Rotates

Bits shifted out one end are shifted into the other. No bits are lost.

-   **`ROL` (Rotate Left)**: MSB moves to LSB.
-   **`ROR` (Rotate Right)**: LSB moves to MSB.

Used heavily in **Cryptography** (hashing, encryption).

## 💱 Byte Swap (`BSWAP`)

Reverses the byte order of a register (Little Endian <-> Big Endian).

```asm
mov eax, 0x12345678
bswap eax       ; EAX = 0x78563412
```
Use this when reading network packets (which are Big Endian).

## 🧪 Bit Scanning

Find the first set bit (1).

-   **`BSF` (Bit Scan Forward)**: Find LSB (Trailing Zeros).
    Equivalent to `__builtin_ctz`.
-   **`BSR` (Bit Scan Reverse)**: Find MSB (Leading Zeros - sort of).
    Equivalent to `31 - __builtin_clz`.

---
[[00-Index|Back to Assembly Index]]
