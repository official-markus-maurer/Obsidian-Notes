# Unit Testing Basics

Unit testing involves testing individual units (functions) of source code to determine if they are fit for use.

## 🎯 Why Unit Test?
1.  **Regression Testing**: Ensure new changes don't break existing functionality.
2.  **Documentation**: Tests show exactly how a function is expected to behave.
3.  **Refactoring Confidence**: You can optimize code fearlessly if tests pass.

## 🧪 Simple Assertion Macro

You can create a basic testing framework using C macros. `assert.h` is good for runtime checks, but for testing, we want a report, not a crash.

```c
#include <stdio.h>

#define ASSERT(cond, msg) do { \
    if (!(cond)) { \
        printf("❌ FAILED: %s (%s:%d)\n", msg, __FILE__, __LINE__); \
        return 0; \
    } \
    printf("✅ PASSED: %s\n", msg); \
} while(0)

// Function to test
int add(int a, int b) {
    return a + b;
}

// Test Case
int test_add() {
    ASSERT(add(2, 3) == 5, "2 + 3 should be 5");
    ASSERT(add(-1, 1) == 0, "-1 + 1 should be 0");
    return 1;
}

int main() {
    if (test_add()) {
        printf("All tests passed.\n");
    } else {
        printf("Some tests failed.\n");
    }
    return 0;
}
```

## 🧠 Test Driven Development (TDD)
1.  **Red**: Write a failing test (because the feature isn't implemented yet).
2.  **Green**: Write just enough code to make the test pass.
3.  **Refactor**: Improve the code while keeping tests green.

## ⚠️ Limitations of Simple Macros
-   Hard to isolate tests (if one crashes, all stop).
-   No automatic test discovery.
-   Limited output formatting.

For real projects, use **Unity**, **CUnit**, or **Google Test** (C++ but works for C).

---
[[00-Index|Back to Testing Index]]
