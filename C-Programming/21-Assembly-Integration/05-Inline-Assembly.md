# Inline Assembly (GCC/Clang)

Inline assembly allows you to embed assembly instructions directly into your C code.

## 📝 Syntax (AT&T)

```c
asm [volatile] ( 
    "assembly code" 
    : output operands   /* optional */
    : input operands    /* optional */
    : clobbered list    /* optional */
);
```

### 1. Simple Example (No Output)

```c
// Force a breakpoint (INT 3)
asm ("int $3");
```

### 2. Output Operands (`=`)

```c
int result;
int a = 10, b = 20;

// Add a + b -> result
asm ("addl %%ebx, %%eax;"
     : "=a" (result)    // Output: store result in 'result' (uses EAX)
     : "a" (a), "b" (b) // Input: load 'a' into EAX, 'b' into EBX
);
```
-   `"=a"`: Use EAX/RAX for output.
-   `"a"`: Use EAX/RAX for input.
-   `"b"`: Use EBX/RBX for input.

### 3. Clobbered Registers

Tell the compiler which registers your assembly modifies (besides output).

```c
// CPUID instruction modifies EAX, EBX, ECX, EDX
int cpu_info[4];
asm ("cpuid"
     : "=a"(cpu_info[0]), "=b"(cpu_info[1]), "=c"(cpu_info[2]), "=d"(cpu_info[3])
     : "a"(0)
);
```
Here, all 4 registers are outputs, so no clobber list is needed.

### 4. Volatile Keyword

By default, GCC may optimize away `asm` blocks if outputs are unused. `volatile` prevents this.

```c
// Memory barrier
asm volatile ("" ::: "memory");
```
This tells the compiler: "Do not reorder memory accesses across this point."

## ⚠️ Constraints Cheatsheet

| Constraint | Meaning |
| :--- | :--- |
| `"r"` | Any General Purpose Register |
| `"m"` | Memory Operand |
| `"i"` | Immediate Integer |
| `"a"` | `RAX` / `EAX` / `AL` |
| `"b"` | `RBX` / `EBX` / `BL` |
| `"c"` | `RCX` / `ECX` / `CL` |
| `"d"` | `RDX` / `EDX` / `DL` |
| `"S"` | `RSI` / `ESI` |
| `"D"` | `RDI` / `EDI` |

---
[[00-Index|Back to Assembly Index]]
