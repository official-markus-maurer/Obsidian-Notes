# Assembly Optimization

Sometimes the compiler's optimizations (`-O3`) aren't enough. You might need to hand-tune critical loops in assembly.

## 🔄 Loop Unrolling

Loop unrolling reduces the overhead of loop control instructions (`inc`, `cmp`, `jne`).

### Standard Loop (C)
```c
for (int i = 0; i < 4; i++) {
    sum += arr[i];
}
```

### Standard Loop (Assembly)
```asm
loop_start:
    add eax, [rdi + rcx*4]  ; Add arr[i]
    inc rcx                 ; i++
    cmp rcx, 4              ; Check end
    jne loop_start          ; Jump back
```
*Overhead: 3 instructions per addition.*

### Unrolled Loop (Assembly)
```asm
    add eax, [rdi]          ; arr[0]
    add eax, [rdi + 4]      ; arr[1]
    add eax, [rdi + 8]      ; arr[2]
    add eax, [rdi + 12]     ; arr[3]
```
*Overhead: 0 instructions. Pipeline can execute additions in parallel.*

## 🚀 Vectorization (SIMD)

Processing multiple data points with a single instruction.

### Scalar Addition (4 floats)
Requires 4 `ADDSS` instructions.

### Vector Addition (4 floats)
Requires 1 `ADDPS` instruction.

```asm
movups xmm0, [rdi]      ; Load 4 floats
addps  xmm0, [rsi]      ; Add 4 floats from other array
movups [rdi], xmm0      ; Store result
```

## 📉 Eliminating Branches

Branch mispredictions are expensive (flush pipeline). Use conditional moves (`CMOV`) instead of jumps.

### Branch (Slow if unpredictable)
```asm
    cmp rax, rbx
    jl skip
    mov rax, rbx
skip:
```

### Conditional Move (Fast)
```asm
    cmp rax, rbx
    cmovl rax, rbx      ; Move if Less
```
*Note: CMOV executes both paths (data dependency), so it's only faster for simple operations.*

---
[[00-Index|Back to Assembly Index]]
