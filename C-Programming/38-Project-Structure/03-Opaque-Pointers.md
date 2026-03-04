# Opaque Pointers (Pimpl Idiom)

C structs are public by default. If you define a struct in a header, users can access its members directly. This breaks encapsulation.
To create "private" members, use **Opaque Pointers**.

## The Concept
Declare the struct in the header, but define it in the `.c` file.

## Implementation

**1. Public Header (`mylib.h`)**
```c
#pragma once

// Forward declaration only
typedef struct MyContext MyContext;

// Constructor
MyContext* context_create(void);

// Methods
void context_do_something(MyContext* ctx);

// Destructor
void context_destroy(MyContext* ctx);
```

**2. Implementation (`mylib.c`)**
```c
#include "mylib.h"
#include <stdlib.h>

// Full definition is hidden here
struct MyContext {
    int internal_state;
    char* buffer;
};

MyContext* context_create(void) {
    MyContext* ctx = malloc(sizeof(MyContext));
    ctx->internal_state = 0;
    return ctx;
}

void context_do_something(MyContext* ctx) {
    // We can access members here
    ctx->internal_state++;
}

void context_destroy(MyContext* ctx) {
    free(ctx);
}
```

## User Code (`main.c`)
```c
#include "mylib.h"

int main() {
    MyContext* ctx = context_create();
    
    context_do_something(ctx);
    
    // ctx->internal_state = 5; // ERROR: Dereferencing pointer to incomplete type
    
    context_destroy(ctx);
    return 0;
}
```

## Benefits
-   **Encapsulation**: Users cannot mess with internal state.
-   **ABI Stability**: You can change the struct layout (add/remove members) without recompiling user code (only the library needs recompiling).

---
[[00-Index|Back to Index]]
