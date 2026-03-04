# Calling C from Python

Python is slow. C is fast. You can speed up Python code by rewriting performance-critical sections in C and calling them using `ctypes` or `CFFI`.

## 1. Write C Code (`mylib.c`)
The C functions must be "exported" (visible to the linker). On Linux/macOS, all non-static functions are exported by default. On Windows, you need `__declspec(dllexport)`.

```c
// mylib.c
#include <stdio.h>

#ifdef _WIN32
#define EXPORT __declspec(dllexport)
#else
#define EXPORT
#endif

EXPORT int add(int a, int b) {
    return a + b;
}

EXPORT void print_array(int *arr, int size) {
    printf("C Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
```

## 2. Compile to Shared Library

-   **Linux**: `gcc -shared -o mylib.so -fPIC mylib.c`
-   **macOS**: `gcc -shared -o mylib.dylib -fPIC mylib.c`
-   **Windows**: `gcc -shared -o mylib.dll mylib.c`

## 3. Call from Python (`main.py`)

Use the built-in `ctypes` library.

```python
import ctypes
import os

# 1. Load Library
lib_name = './mylib.so'
if os.name == 'nt':
    lib_name = './mylib.dll'

lib = ctypes.CDLL(lib_name)

# 2. Define Argument Types (Crucial for 64-bit safety!)
lib.add.argtypes = [ctypes.c_int, ctypes.c_int]
lib.add.restype = ctypes.c_int

# 3. Call Simple Function
result = lib.add(10, 20)
print(f"10 + 20 = {result}")

# 4. Pass Array (Pointers)
IntArray5 = ctypes.c_int * 5
arr = IntArray5(1, 2, 3, 4, 5)

lib.print_array.argtypes = [ctypes.POINTER(ctypes.c_int), ctypes.c_int]
lib.print_array(arr, 5)
```

## ⚠️ Common Pitfalls
1.  **ABI Mismatch**: 32-bit Python cannot load 64-bit DLLs (and vice versa).
2.  **Memory Management**: If C allocates memory (`malloc`), Python doesn't know how to free it. You must export a `free_memory()` function in C and call it from Python.

---
[[00-Index|Back to Interop Index]]
