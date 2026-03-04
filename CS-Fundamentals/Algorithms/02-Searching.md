# Searching Algorithms

## Binary Search
Works only on sorted arrays. O(log n).

```c
#include <stdlib.h>

int compare(const void *key, const void *element) {
    return (*(int*)key - *(int*)element);
}

int main() {
    int arr[] = {1, 2, 5, 5, 9};
    int key = 5;
    int *found = bsearch(&key, arr, 5, sizeof(int), compare);
    return 0;
}
```

## Linear Search
Simple iteration. O(n). Used when the array is unsorted or very small.

---
[[00-Index|Back to Index]]
