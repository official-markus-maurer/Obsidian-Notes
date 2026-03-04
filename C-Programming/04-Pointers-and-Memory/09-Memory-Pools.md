# Memory Pools (Arena Allocators)

Standard `malloc` and `free` are general-purpose but slow and prone to fragmentation. For high-performance systems (games, compilers), **Arena Allocators** are preferred.

## 🏟️ The Concept

Instead of allocating individual blocks, you allocate one huge block (the Arena) and simply increment a pointer to "allocate" memory. To free, you just reset the pointer to the start.

## 🚀 Implementation

```c
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

typedef struct {
    uint8_t *buffer;
    size_t length;
    size_t offset;
} Arena;

Arena Arena_Create(size_t size) {
    Arena a;
    a.buffer = malloc(size);
    a.length = size;
    a.offset = 0;
    return a;
}

void* Arena_Alloc(Arena *a, size_t size) {
    if (a->offset + size > a->length) {
        return NULL; // Out of memory
    }
    void *ptr = &a->buffer[a->offset];
    a.offset += size;
    return ptr;
}

void Arena_Reset(Arena *a) {
    a->offset = 0; // "Free" everything instantly
}

int main() {
    Arena myArena = Arena_Create(1024 * 1024); // 1MB
    
    int *nums = Arena_Alloc(&myArena, 100 * sizeof(int));
    char *str = Arena_Alloc(&myArena, 50);
    
    // Use memory...
    
    Arena_Reset(&myArena); // All gone! Extremely fast.
    return 0;
}
```

## ✅ Pros
-   **Speed**: Allocation is just an addition instruction.
-   **Cache Locality**: Data is contiguous.
-   **No Leaks**: You free everything at once.

---
[[00-Index|Back to Pointers Index]]
