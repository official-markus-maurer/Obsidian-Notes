# Stack vs Heap

## The Stack
-   **Structure**: LIFO (Last In, First Out).
-   **Allocation**: Automatic (function calls).
-   **Speed**: Very fast (CPU instruction `push`/`pop`).
-   **Size**: Limited (typically a few MB).
-   **Lifetime**: Scope-based.

## The Heap
-   **Structure**: Fragmented pool of memory.
-   **Allocation**: Manual (`malloc` in C, `new` in C++).
-   **Speed**: Slower (requires finding a free block).
-   **Size**: Limited only by physical RAM/Swap.
-   **Lifetime**: Until manually freed.

## Comparison Table
| Feature | Stack | Heap |
| :--- | :--- | :--- |
| **Speed** | Very Fast | Slow |
| **Size** | Small | Large |
| **Management** | Automatic | Manual |
| **Locality** | High (Contiguous) | Low (Fragmented) |

---
[[00-Index|Back to Memory Index]]
