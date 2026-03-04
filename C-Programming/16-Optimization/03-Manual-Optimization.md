# Manual Optimization Techniques

If compiler flags aren't enough, you can optimize the code structure yourself.

## 🔄 Loop Unrolling
Reduces the overhead of loop control code (incrementing counters, checking conditions).

**Standard Loop:**
```c
for (int i = 0; i < 4; i++) {
    process(i);
}
```

**Unrolled Loop:**
```c
process(0);
process(1);
process(2);
process(3);
```
*Note: Modern compilers (-O3) usually do this automatically.*

## 📦 Inline Functions (`inline`)
Reduces function call overhead (pushing args to stack, jumping) by copying the function body directly into the caller.

```c
inline int square(int x) {
    return x * x;
}
```

## 🌳 Branch Prediction Hints (`likely` / `unlikely`)
Tell the compiler which path of an `if` statement is more probable.

```c
#define likely(x)   __builtin_expect(!!(x), 1)
#define unlikely(x) __builtin_expect(!!(x), 0)

if (unlikely(error_code)) {
    // Handle error (compiler moves this code away to improve cache locality for the main path)
}
```

---
[[00-Index|Back to Optimization Index]]
