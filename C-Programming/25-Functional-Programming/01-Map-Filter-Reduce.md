# Map, Filter, Reduce

Higher-order functions take other functions as arguments.

## 🗺️ Map
Apply a function to every element.

```c
void map(int *arr, int size, int (*func)(int)) {
    for (int i = 0; i < size; i++) {
        arr[i] = func(arr[i]);
    }
}

int square(int x) { return x * x; }

// Usage: map(arr, 5, square);
```

## 🔍 Filter
Select elements that satisfy a predicate.

```c
int filter(int *src, int size, int *dest, int (*pred)(int)) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (pred(src[i])) {
            dest[count++] = src[i];
        }
    }
    return count;
}

int is_even(int x) { return x % 2 == 0; }
```

## 📉 Reduce (Fold)
Combine all elements into one value.

```c
int reduce(int *arr, int size, int (*func)(int, int), int init) {
    int result = init;
    for (int i = 0; i < size; i++) {
        result = func(result, arr[i]);
    }
    return result;
}

int add(int a, int b) { return a + b; }

// Usage: int sum = reduce(arr, 5, add, 0);
```

---
[[00-Index|Back to Functional Index]]
