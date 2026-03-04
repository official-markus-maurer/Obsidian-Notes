# Boehm Garbage Collector

The Boehm-Demers-Weiser conservative garbage collector (`libgc`) can be used as a drop-in replacement for `malloc`.

## 📦 Usage

1.  **Install**: `sudo apt install libgc-dev`
2.  **Link**: `gcc -lgc main.c`

## 📝 Code Example

```c
#include <gc.h>
#include <stdio.h>

int main() {
    GC_INIT(); // Initialize collector

    for (int i = 0; i < 1000000; i++) {
        // GC_MALLOC replaces malloc
        // No need to call free()!
        int *p = (int*)GC_MALLOC(sizeof(int));
        *p = i;
    }
    
    // The GC automatically reclaims memory when 'p' goes out of scope
    // or is overwritten.
    
    return 0;
}
```

## ⚖️ Conservative GC
It scans memory (stack, registers, heap) looking for values that *look* like pointers to allocated blocks. If it finds one, it marks the block as used. It might occasionally leak memory if an integer happens to look like a pointer, but it is safe.

---
[[00-Index|Back to GC Index]]
