# Sorting Algorithms

## Built-in `qsort`
The C standard library provides a highly optimized QuickSort implementation.

```c
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int arr[] = {5, 2, 9, 1, 5};
    qsort(arr, 5, sizeof(int), compare);
    return 0;
}
```

## Merge Sort (Divide & Conquer)
Merge sort is stable and guarantees O(n log n), unlike QuickSort's worst-case O(n^2).
It requires O(n) auxiliary space.

---
[[00-Index|Back to Index]]
