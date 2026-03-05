# Register Manipulation

In embedded systems, you control hardware by reading and writing to specific memory addresses called **Registers**.

## 🔢 Bitwise Operations

You rarely change an entire register. Instead, you modify specific bits.

### Setting a Bit (OR)
To set bit `n` to 1:
```c
REGISTER |= (1 << n);
```

### Clearing a Bit (AND NOT)
To set bit `n` to 0:
```c
REGISTER &= ~(1 << n);
```

### Toggling a Bit (XOR)
To flip bit `n`:
```c
REGISTER ^= (1 << n);
```

### Checking a Bit
To check if bit `n` is 1:
```c
if (REGISTER & (1 << n)) {
    // Bit is set
}
```

## 🏗️ Structs for Registers

Instead of raw pointers, use structs to map memory. This is cleaner and type-safe.

```c
#include <stdint.h>

typedef struct {
    volatile uint32_t CR;  // Control Register
    volatile uint32_t SR;  // Status Register
    volatile uint32_t DR;  // Data Register
} UART_TypeDef;

// Base address of UART1 peripheral
#define UART1_BASE 0x40011000
#define UART1 ((UART_TypeDef *) UART1_BASE)

void UART_Send(char c) {
    // Wait for Transmit Data Register Empty (TXE) bit
    while (!(UART1->SR & (1 << 7))); 
    UART1->DR = c;
}
```

## ⚠️ Read-Modify-Write (RMW) Cycle
Be careful with `|=` and `&=` on registers that have "Write 1 to Clear" (W1C) bits or hardware side effects.
Sometimes reading a register clears it! Always check the datasheet.

## 🚀 Assembly Startup Code (Cortex-M)

Before `main()` runs, the microcontroller executes the **Reset Handler** (written in assembly). It must:
1.  Initialize the **Stack Pointer (`SP`)**.
2.  Copy **.data** section from Flash to RAM.
3.  Zero out **.bss** section.
4.  Call `SystemInit()` and `main()`.

```asm
.section .text.Reset_Handler
.weak Reset_Handler
.type Reset_Handler, %function

Reset_Handler:
    ldr   sp, =_estack      ; 1. Load Stack Pointer (from Linker Script)

    ; 2. Copy .data from Flash to RAM (Loop)
    ldr   r0, =_sdata       ; Start of .data in RAM
    ldr   r1, =_edata       ; End of .data in RAM
    ldr   r2, =_sidata      ; Start of .data in Flash
    b     LoopCopyDataInit

CopyDataInit:
    ldr   r3, [r2], #4      ; Read word from Flash
    str   r3, [r0], #4      ; Write word to RAM

LoopCopyDataInit:
    cmp   r0, r1
    bcc   CopyDataInit

    ; 3. Zero .bss (Loop)
    ldr   r2, =_sbss
    ldr   r4, =_ebss
    movs  r3, #0
    b     LoopFillZerobss

FillZerobss:
    str   r3, [r2], #4

LoopFillZerobss:
    cmp   r2, r4
    bcc   FillZerobss

    ; 4. Call main
    bl    main
    b     .                 ; Infinite loop if main returns
```

---
[[00-Index|Back to Embedded Index]]
