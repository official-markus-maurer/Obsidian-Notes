# Control Flow (Jumps & Loops)

Control flow in assembly is handled by modifying the **Instruction Pointer (`RIP`)**. This is done via **Jumps** (like `goto` in C) based on the state of the **Flags Register (`RFLAGS`)**.

## ⚖️ The Compare Instruction (`CMP`)

`CMP` compares two values by performing a subtraction (`dest - src`) and discarding the result, but updating the flags.

```asm
cmp rax, 10
; If rax == 10, ZF (Zero Flag) = 1
; If rax < 10,  SF (Sign Flag) != OF (Overflow Flag)
; If rax > 10,  ZF = 0 and SF = OF
```

## 🦘 Conditional Jumps

After a `CMP` (or `TEST`), you use a conditional jump.

| Instruction | Meaning | Flags Checked | C Equivalent |
|---|---|---|---|
| `JE` / `JZ` | Jump if Equal / Zero | ZF = 1 | `==` |
| `JNE` / `JNZ` | Jump if Not Equal / Not Zero | ZF = 0 | `!=` |
| `JG` / `JNLE` | Jump if Greater (Signed) | ZF = 0, SF = OF | `>` |
| `JL` / `JNGE` | Jump if Less (Signed) | SF != OF | `<` |
| `JGE` / `JNL` | Jump if Greater/Equal (Signed) | SF = OF | `>=` |
| `JLE` / `JNG` | Jump if Less/Equal (Signed) | ZF = 1 or SF != OF | `<=` |
| `JA` / `JNBE` | Jump if Above (Unsigned) | CF = 0, ZF = 0 | `>` (unsigned) |
| `JB` / `JNAE` | Jump if Below (Unsigned) | CF = 1 | `<` (unsigned) |

## 🔄 Implementing Loops

Loops are just jumps that go backwards.

### C Code
```c
for (int i = 0; i < 10; i++) {
    // do work
}
```

### Assembly (Intel Syntax)
```asm
    mov rcx, 0          ; i = 0

loop_start:
    cmp rcx, 10         ; compare i with 10
    jge loop_end        ; if i >= 10, jump to end

    ; do work...

    inc rcx             ; i++
    jmp loop_start      ; jump back to start

loop_end:
    ; continue...
```

## 🧪 The `TEST` Instruction
Performs a bitwise AND (`dest & src`) and discards result. Used to check for 0 or specific bits.

```asm
test rax, rax   ; Check if RAX is 0
jz is_zero      ; Jump if 0
js is_negative  ; Jump if negative (Sign Flag set)
```

---
[[00-Index|Back to Assembly Index]]
