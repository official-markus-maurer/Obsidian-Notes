# Set Theory

A Set is a collection of unique elements.

## Bitmasks as Sets
In C, a `uint32_t` can represent a set of numbers {0..31}.

```c
#define SET_A (1 << 0) // Element 0
#define SET_B (1 << 1) // Element 1

uint32_t set = 0;

// Union (Add element)
set |= SET_A;

// Intersection (Check if present)
if (set & SET_A) { ... }

// Difference (Remove element)
set &= ~SET_A;
```

This is extremely fast and memory-efficient compared to HashSets, but limited to small integers.

---
[[00-Index|Back to Index]]
