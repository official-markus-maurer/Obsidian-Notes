# C and C++ Interoperability

C++ is mostly compatible with C, but C++ compilers "mangle" function names to support features like function overloading (e.g., `add(int)` vs `add(float)`). C compilers do not.

## 🛑 The Problem

If you compile C code with a C++ compiler, or try to link C++ objects with C objects, the linker won't find the function names because they look different.

## ✅ The Solution: `extern "C"`

Wrap your C declarations in `extern "C"` to tell the C++ compiler: "Treat these functions as C functions (do not mangle names)."

```c
// myheader.h

#ifdef __cplusplus
extern "C" {
#endif

void my_c_function(int x);

#ifdef __cplusplus
}
#endif
```

Now this header can be included safely in both `.c` and `.cpp` files.

---
[[00-Index|Back to Interop Index]]
