# Unit Testing Basics

Unit testing involves testing individual units (functions) of source code to determine if they are fit for use.

## 🧪 Simple Assertion Macro

You can create a basic testing framework using C macros and `assert.h`.

```c
#include <stdio.h>
#include <assert.h>

// Function to test
int add(int a, int b) {
    return a + b;
}

// Test Case
void test_add() {
    assert(add(2, 3) == 5);
    assert(add(-1, 1) == 0);
    printf("test_add passed!\n");
}

int main() {
    test_add();
    printf("All tests passed.\n");
    return 0;
}
```

## ⚠️ Limitations
-   `assert()` aborts the program on the first failure.
-   No summary of passed/failed tests.
-   Hard to manage hundreds of tests.

For larger projects, use a dedicated framework like **Unity**, **CUnit**, or **Check**.

---
[[00-Index|Back to Testing Index]]
