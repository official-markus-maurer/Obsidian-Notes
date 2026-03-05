# Common Instructions

## 🚚 Data Movement

### MOV (Move)
Copies data from source to destination.
`mov dest, src`

```asm
mov rax, 10         ; rax = 10
mov rbx, rcx        ; rbx = rcx
mov [rbp-8], rax    ; Write rax to memory at [rbp-8]
```

### LEA (Load Effective Address)
Calculates an address but does **not** access memory. Used for pointer arithmetic.
`lea dest, [address]`

```asm
lea rax, [rbx + 4]  ; rax = rbx + 4 (Does NOT read memory!)
```

## 🧮 Arithmetic

### ADD / SUB (Add / Subtract)
`add dest, src` (dest += src)
`sub dest, src` (dest -= src)

### INC / DEC (Increment / Decrement)
`inc rax` (rax++)
`dec rbx` (rbx--)

### IMUL (Integer Multiply)
`imul dest, src` (dest *= src)

### IDIV (Integer Divide)
Requires `RAX:RDX` (128-bit pair) as dividend.
`cdq` extends `EAX` to `EDX:EAX`.
`idiv src` (RAX = quotient, RDX = remainder)

## ⚖️ Comparison and Jumps

### CMP (Compare)
Performs `sub dest, src` but discards the result, updating flags.

### JMP (Unconditional Jump)
`jmp label`

### Conditional Jumps
Based on flags (from CMP).
-   `je`: Jump if Equal (ZF=1)
-   `jne`: Jump if Not Equal (ZF=0)
-   `jg`: Jump if Greater (Signed)
-   `jl`: Jump if Less (Signed)
-   `ja`: Jump if Above (Unsigned)
-   `jb`: Jump if Below (Unsigned)

## 📞 Functions

### CALL
1.  Push RIP (Return Address) to stack.
2.  Jump to function address.

### RET
1.  Pop RIP from stack.
2.  Jump to that address.

### PUSH / POP
Manipulate the stack (RSP).
`push rax`: Decrement RSP by 8, write RAX.
`pop rax`: Read RAX from [RSP], increment RSP by 8.

---
[[00-Index|Back to Assembly Index]]
