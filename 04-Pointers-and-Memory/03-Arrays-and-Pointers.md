# Arrays and Pointers

Arrays and pointers are closely related in C. In fact, the name of an array acts like a constant pointer to the first element of the array.

## 🔗 The Relationship
`arr` is equivalent to `&arr[0]`.

```c
int arr[5] = {1, 2, 3, 4, 5};
int *ptr = arr; // Valid
```

Accessing elements:
- `arr[i]` is equivalent to `*(arr + i)`
- `&arr[i]` is equivalent to `arr + i`

## 📦 Passing Arrays to Functions
When you pass an array to a function, it decays into a pointer to its first element. This is why you often need to pass the size of the array separately.

```c
void printArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]); // or *(arr + i)
    }
    printf("\n");
}

int main() {
    int myArr[] = {10, 20, 30};
    printArray(myArr, 3);
    return 0;
}
```

## 🚫 Difference
- **Array Name**: Constant pointer (address cannot be changed). `arr++` is invalid.
- **Pointer Variable**: Can be changed to point elsewhere. `ptr++` is valid.

---
[[00-Index|Back to Pointers Index]]
