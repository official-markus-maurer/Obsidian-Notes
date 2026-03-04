# Generic Data Structures

Since C lacks templates (C++) or generics (Java/C#), we must use other techniques to create reusable data structures that work with any type.

## 🛠️ Approach 1: `void*` Pointers

This is the most common approach. The data structure stores pointers to data, rather than the data itself.

### Example: Generic Stack

```c
#include <stdlib.h>
#include <stdio.h>

typedef struct {
    void **items;
    int top;
    int capacity;
} Stack;

Stack* Stack_Create(int capacity) {
    Stack *s = malloc(sizeof(Stack));
    s->capacity = capacity;
    s->top = -1;
    s->items = malloc(capacity * sizeof(void*));
    return s;
}

void Stack_Push(Stack *s, void *item) {
    if (s->top < s->capacity - 1) {
        s->items[++s->top] = item;
    }
}

void* Stack_Pop(Stack *s) {
    if (s->top >= 0) {
        return s->items[s->top--];
    }
    return NULL;
}

int main() {
    Stack *s = Stack_Create(10);
    int a = 10, b = 20;
    
    Stack_Push(s, &a);
    Stack_Push(s, &b);
    
    int *val = (int*)Stack_Pop(s);
    printf("Popped: %d\n", *val);
    
    return 0;
}
```
**Pros**: Works for any type.
**Cons**: No type safety (must cast). Performance overhead (indirection).

## 🛠️ Approach 2: Macros

Macros can generate type-specific code at compile time, similar to C++ templates.

```c
#define DEFINE_VECTOR(Type) \
    typedef struct { \
        Type *data; \
        int size; \
        int capacity; \
    } Vector_##Type; \
    \
    void Vector_Push_##Type(Vector_##Type *v, Type item) { \
        v->data[v->size++] = item; \
    }

// Usage
DEFINE_VECTOR(int)

int main() {
    Vector_int v = {malloc(10 * sizeof(int)), 0, 10};
    Vector_Push_int(&v, 42);
}
```
**Pros**: Type safe, high performance.
**Cons**: Hard to debug, increases code size.

---
[[00-Index|Back to Data Structures Index]]
