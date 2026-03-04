# Freestanding Environment

A **Hosted Environment** provides the standard library (libc). A **Freestanding Environment** does not.

## 🛠️ The Flag: `-ffreestanding`

When compiling a kernel, you must tell GCC not to assume standard library presence.

```bash
gcc -ffreestanding -c kernel.c -o kernel.o
```

## 🚫 What is missing?
-   `stdio.h` (`printf`, `fopen`)
-   `stdlib.h` (`malloc`, `exit`)
-   `string.h` (mostly missing, though you can implement your own easily)

## ✅ What is available?
-   `<stdint.h>` (`uint8_t`, `int32_t`)
-   `<stddef.h>` (`size_t`)
-   `<stdbool.h>` (`bool`)

You must implement everything else yourself!

---
[[00-Index|Back to Kernel Index]]
