# Stack Operations (x86-64)

The **Stack** is a memory region used for temporary storage, local variables, and function calls. It grows **downwards** (from high memory addresses to low).

## 🗄️ Stack Pointer (`RSP`)
-   Points to the **top** element of the stack.
-   **Pushing** data decrements `RSP` by 8 (on 64-bit systems).
-   **Popping** data increments `RSP` by 8.

## 📥 Pushing Data (`PUSH`)

1.  Decrements `RSP` by 8.
2.  Writes the value to the address pointed to by `RSP`.

```asm
mov rax, 0x12345678
push rax            ; RSP -= 8, [RSP] = 0x12345678
push rbx            ; RSP -= 8, [RSP] = RBX
```

## 📤 Popping Data (`POP`)

1.  Reads the value from `[RSP]`.
2.  Increments `RSP` by 8.
3.  Writes the value to the destination register.

```asm
pop rbx             ; RBX = [RSP], RSP += 8
pop rax             ; RAX = [RSP], RSP += 8
```

## 🏗️ Stack Frames (Base Pointer `RBP`)

To manage local variables and arguments, functions use a **Stack Frame**.

### Function Prologue
Sets up the stack frame.
```asm
push rbp            ; Save the caller's base pointer
mov rbp, rsp        ; Set new base pointer to current stack top
sub rsp, 16         ; Allocate 16 bytes for local variables
```

### Function Epilogue
Cleans up the stack frame before returning.
```asm
mov rsp, rbp        ; Restore stack pointer (deallocates locals)
pop rbp             ; Restore caller's base pointer
ret                 ; Return to caller
```
*Note: The `LEAVE` instruction is equivalent to `mov rsp, rbp; pop rbp`.*

## ⚠️ Alignment Requirement
The stack must be **16-byte aligned** before a `CALL` instruction (System V ABI). If you push an odd number of 64-bit registers, you might need to add padding (sub rsp, 8) before calling another function.

---
[[00-Index|Back to Assembly Index]]
