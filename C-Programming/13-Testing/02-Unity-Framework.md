# Unity Test Framework

Unity is a lightweight, portable unit testing framework for C. It is especially popular in embedded systems due to its minimal footprint.

## 📥 Setup

1.  Download `unity.c` and `unity.h` from the [Unity Repo](https://github.com/ThrowTheSwitch/Unity).
2.  Add them to your project's `src` or `tests` directory.

## 📝 Writing a Test Suite

Create a file `test_main.c`:

```c
#include "unity.h"
#include "my_math.h" // The module you are testing

// Runs BEFORE every test
void setUp(void) {
    // Initialize variables, open files, etc.
}

// Runs AFTER every test
void tearDown(void) {
    // Free memory, close files, etc.
}

void test_Addition_Should_AddTwoNumbers(void) {
    TEST_ASSERT_EQUAL_INT(5, add(2, 3));
    TEST_ASSERT_EQUAL_INT(-2, add(-5, 3));
}

void test_Division_Should_HandleZero(void) {
    TEST_ASSERT_EQUAL_FLOAT(0.0, divide(10, 0)); // Assuming your function handles it
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_Addition_Should_AddTwoNumbers);
    RUN_TEST(test_Division_Should_HandleZero);
    return UNITY_END();
}
```

## 🔍 Common Assertions

### Integers
-   `TEST_ASSERT_EQUAL_INT(expected, actual)`
-   `TEST_ASSERT_INT_WITHIN(delta, expected, actual)`: Range check.
-   `TEST_ASSERT_GREATER_THAN(threshold, actual)`

### Strings
-   `TEST_ASSERT_EQUAL_STRING("hello", str)`
-   `TEST_ASSERT_EQUAL_STRING_LEN("hello", str, 5)`

### Memory & Pointers
-   `TEST_ASSERT_NULL(pointer)`
-   `TEST_ASSERT_NOT_NULL(pointer)`
-   `TEST_ASSERT_EQUAL_MEMORY(expected_buf, actual_buf, len)`

### Arrays
-   `TEST_ASSERT_EQUAL_INT_ARRAY(expected, actual, num_elements)`

## 🚀 Running Tests
Compile your test file with `unity.c` and your source code.

```bash
gcc test_main.c unity.c ../src/my_math.c -I../src -o run_tests
./run_tests
```

**Output:**
```
test_main.c:14:test_Addition_Should_AddTwoNumbers:PASS
test_main.c:19:test_Division_Should_HandleZero:PASS
-----------------------
2 Tests 0 Failures 0 Ignored
OK
```

---
[[00-Index|Back to Testing Index]]
