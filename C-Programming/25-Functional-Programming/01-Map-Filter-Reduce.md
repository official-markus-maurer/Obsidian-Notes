# Map, Filter, Reduce

C supports functional programming concepts through **Function Pointers**.

## 🗺️ Map
Transforms each element in an array using a function.

```c
#include <stdio.h>

// Applies 'func' to every element of 'arr'
void map(int *arr, size_t size, int (*func)(int)) {
    for (size_t i = 0; i < size; i++) {
        arr[i] = func(arr[i]);
    }
}

int square(int x) { return x * x; }

int main() {
    int data[] = {1, 2, 3, 4, 5};
    map(data, 5, square);
    // data is now {1, 4, 9, 16, 25}
}
```

## 🔍 Filter
Selects elements that satisfy a predicate.

```c
// Copies elements where pred(x) is true into dest. Returns new size.
size_t filter(const int *src, size_t size, int *dest, int (*pred)(int)) {
    size_t count = 0;
    for (size_t i = 0; i < size; i++) {
        if (pred(src[i])) {
            dest[count++] = src[i];
        }
    }
    return count;
}

int is_even(int x) { return x % 2 == 0; }
```

## 📉 Reduce (Fold)
Accumulates all elements into a single value.

```c
// Combines elements: func(init, arr[0]) -> acc, func(acc, arr[1]) -> acc...
int reduce(const int *arr, size_t size, int (*func)(int, int), int init) {
    int result = init;
    for (size_t i = 0; i < size; i++) {
        result = func(result, arr[i]);
    }
    return result;
}

int add(int a, int b) { return a + b; }
// Usage: int sum = reduce(data, 5, add, 0);
```

## ⚠️ Caveats
-   **No Closures**: Standard C function pointers cannot capture local variables. You need a "context" pointer (`void *ctx`) to simulate this (see [[02-Closures|Closures]]).
-   **Performance**: Function pointers prevent inlining (unless LTO is enabled), which can be slower than a simple loop.

---
[[00-Index|Back to Functional Index]]
