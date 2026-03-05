# ARM64 (AArch64) Assembly Basics

ARM64 is the architecture used by modern mobile devices (Android, iOS), Apple Silicon (M1/M2/M3), and many servers. It is a **RISC** (Reduced Instruction Set Computer) architecture, unlike x86 (CISC).

## 📋 Key Differences from x86-64

| Feature | x86-64 (CISC) | ARM64 (RISC) |
| :--- | :--- | :--- |
| **Instruction Length** | Variable (1-15 bytes) | Fixed (4 bytes) |
| **Registers** | Few (`RAX`, `RBX`...) | Many (`X0`-`X30`) |
| **Memory Access** | Most instructions can access memory | **Load/Store Only** (`LDR`, `STR`) |
| **Endianness** | Little Endian | Bi-Endian (usually Little) |

## 💾 Registers

### General Purpose (`X0` - `X30`)
-   **64-bit**: `X0` - `X30`
-   **32-bit**: `W0` - `W30` (Lower half of Xn)

**Special Roles**:
-   `X0` - `X7`: Arguments and Return Values.
-   `X8`: Indirect result location (struct return).
-   `X9` - `X15`: Temporary (Caller-saved).
-   `X19` - `X28`: Callee-saved.
-   `X29` (`FP`): Frame Pointer.
-   `X30` (`LR`): Link Register (Return Address).
-   `SP`: Stack Pointer.
-   `PC`: Program Counter (Cannot be accessed directly).
-   `XZR` / `WZR`: Zero Register (Always reads 0, writes discarded).

## 🚚 Load and Store (LDR/STR)

You cannot do `ADD [X0], X1`. You must load to a register, add, then store.

```asm
; Load 64-bit value from address in X1 into X0
LDR X0, [X1]

; Store 32-bit value from W0 to address in X1
STR W0, [X1]

; Load with Offset
LDR X0, [X1, #8]    ; X0 = *(X1 + 8)

; Pre-Index (Update base register BEFORE access)
LDR X0, [X1, #8]!   ; X1 += 8; X0 = *X1

; Post-Index (Update base register AFTER access)
LDR X0, [X1], #8    ; X0 = *X1; X1 += 8
```

## 🧮 Arithmetic

Three operands: `Op Dest, Src1, Src2`

```asm
ADD X0, X1, X2      ; X0 = X1 + X2
SUB X0, X1, #10     ; X0 = X1 - 10
MUL X0, X1, X2      ; X0 = X1 * X2
```

## 📞 Function Calls (BL / RET)

-   **`BL label` (Branch with Link)**:
    1.  Stores next instruction address in `LR` (`X30`).
    2.  Jumps to `label`.
-   **`RET`**:
    1.  Jumps to address in `LR` (`X30`).

**Leaf Function Optimization**:
Since `RET` uses `LR`, leaf functions don't need to touch the stack!
```asm
; int add(int a, int b)
add_func:
    ADD W0, W0, W1  ; Return value in W0
    RET             ; Return to LR
```

**Non-Leaf Functions**:
Must save `LR` (and `FP`) to stack because `BL` will overwrite `LR`.
```asm
non_leaf:
    STP X29, X30, [SP, #-16]! ; Push FP and LR
    MOV X29, SP               ; Setup Frame Pointer
    
    BL  other_func
    
    LDP X29, X30, [SP], #16   ; Pop FP and LR
    RET
```

## ⚖️ Comparison and Branching

```asm
CMP X0, X1          ; Set flags based on X0 - X1
BEQ label           ; Branch if Equal
BNE label           ; Branch if Not Equal
BGT label           ; Branch if Greater Than
BLT label           ; Branch if Less Than
```

**Compare and Branch Zero (CBZ)**:
Special instruction for efficient checks.
```asm
CBZ X0, label       ; Branch if X0 == 0
CBNZ X0, label      ; Branch if X0 != 0
```

---
[[00-Index|Back to Assembly Index]]
