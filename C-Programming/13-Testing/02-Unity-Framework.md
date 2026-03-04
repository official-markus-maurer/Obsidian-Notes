# Unity Test Framework

Unity is a lightweight unit testing framework for C, popular in embedded systems.

## 📥 Setup

1.  Download `unity.c` and `unity.h` from the [Unity Repo](https://github.com/ThrowTheSwitch/Unity).
2.  Include them in your project.

## 📝 Writing a Test

```c
#include "unity.h"
#include "my_math.h" // The module you are testing

void setUp(void) {
    // Run before each test
}

void tearDown(void) {
    // Run after each test
}

void test_Addition_Should_AddTwoNumbers(void) {
    TEST_ASSERT_EQUAL_INT(5, add(2, 3));
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_Addition_Should_AddTwoNumbers);
    return UNITY_END();
}
```

## 🔍 Common Assertions
-   `TEST_ASSERT_EQUAL_INT(expected, actual)`
-   `TEST_ASSERT_EQUAL_FLOAT(expected, actual)`
-   `TEST_ASSERT_NULL(pointer)`
-   `TEST_ASSERT_TRUE(condition)`

---
[[00-Index|Back to Testing Index]]
