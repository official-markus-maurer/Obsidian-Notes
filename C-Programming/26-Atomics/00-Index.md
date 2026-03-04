# Atomic Operations (C11/C23)

Before C11, atomics were non-standard (compiler-specific). C11 introduced `<stdatomic.h>`, enabling lock-free programming.

## 📋 Topics

1.  **[[01-Atomic-Types|Atomic Types]]**
    -   `_Atomic` keyword
    -   `atomic_int`, `atomic_flag`

2.  **[[02-Memory-Ordering|Memory Ordering]]**
    -   `memory_order_relaxed`, `memory_order_seq_cst`
    -   Fences and Barriers

---
**Next Section**: [[../27-Advanced-Networking/00-Index|Advanced Networking]]
