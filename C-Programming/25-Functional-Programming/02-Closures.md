# Simulating Closures

A closure is a function bundled with its environment (variables). C doesn't have closures, but we can simulate them using a struct context.

## 🛠️ The Context Pattern

```c
#include <stdio.h>

typedef struct {
    int multiplier;
} Context;

// Function takes context
int multiply_with_context(void *ctx, int val) {
    Context *c = (Context*)ctx;
    return val * c->multiplier;
}

// Generic Executor
void execute(int val, int (*func)(void*, int), void *ctx) {
    printf("Result: %d\n", func(ctx, val));
}

int main() {
    Context ctx1 = {2};
    Context ctx2 = {10};
    
    execute(5, multiply_with_context, &ctx1); // 5 * 2 = 10
    execute(5, multiply_with_context, &ctx2); // 5 * 10 = 50
    
    return 0;
}
```
This pattern is widely used in C libraries (like `pthread_create`, GTK callbacks) where a `void *user_data` is passed to the callback.

---
[[00-Index|Back to Functional Index]]
