# Calling C from Python

You can speed up Python code by rewriting performance-critical sections in C.

## 1. Write C Code (`mylib.c`)

```c
// mylib.c
int add(int a, int b) {
    return a + b;
}
```

## 2. Compile to Shared Library

**Linux/Mac**:
```bash
gcc -shared -o mylib.so -fPIC mylib.c
```
**Windows**:
```bash
gcc -shared -o mylib.dll mylib.c
```

## 3. Call from Python (`main.py`)

Use the built-in `ctypes` library.

```python
import ctypes
import os

# Load library
if os.name == 'nt':
    lib = ctypes.CDLL('./mylib.dll')
else:
    lib = ctypes.CDLL('./mylib.so')

# Call function
result = lib.add(10, 20)
print(f"Result from C: {result}")
```

---
[[00-Index|Back to Interop Index]]
