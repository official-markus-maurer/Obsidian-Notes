# Data Types (Assembly)

In high-level languages like C, you have types like `int`, `char`, `float`. In assembly, you only have **bytes** and **interpretation**.

## 📏 Sizes

| C Type | Assembly Size | NASM Keyword | Bytes |
| :--- | :--- | :--- | :--- |
| `char` | Byte | `BYTE` | 1 |
| `short` | Word | `WORD` | 2 |
| `int` | Double Word | `DWORD` | 4 |
| `long` / `ptr` | Quad Word | `QWORD` | 8 |
| `__int128` | Double Quad | `DQWORD` / `XMM` | 16 |

### Specifying Size
When moving immediate values to memory, the assembler doesn't know the size. You must be explicit.

```asm
mov [rax], 1        ; Error: Operation size not specified
mov byte [rax], 1   ; Store 1 byte (0x01)
mov dword [rax], 1  ; Store 4 bytes (0x01 00 00 00)
```

## 🔄 Endianness

x86-64 is **Little Endian**. This means the **least significant byte** is stored at the lowest address.

Value: `0x12345678` (32-bit integer)
Address `0x100`: `0x78`
Address `0x101`: `0x56`
Address `0x102`: `0x34`
Address `0x103`: `0x12`

### Implications
If you write a 32-bit value and read it back as bytes, you get them in reverse order.

```asm
mov dword [rsp], 0x12345678
mov al, [rsp]       ; AL = 0x78 (Not 0x12!)
```

## ➕ Signed vs Unsigned

The CPU doesn't know if a register holds a signed or unsigned number. It's up to **you** to use the correct instruction.

### Arithmetic
`ADD` and `SUB` work the same for both (thanks to Two's Complement).
`MUL` (Unsigned) vs `IMUL` (Signed).
`DIV` (Unsigned) vs `IDIV` (Signed).

### Extension (Casting)
When moving a smaller value to a larger register:
-   **Zero Extension (Unsigned)**: Fill upper bits with 0.
    `MOVZX rax, bl`
-   **Sign Extension (Signed)**: Fill upper bits with the sign bit (preserve negative).
    `MOVSX rax, bl`
    `CDQE` (Convert Double to Quad Extended: EAX -> RAX)

---
[[00-Index|Back to Assembly Index]]
