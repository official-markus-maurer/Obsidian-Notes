# Reference Counting

Reference counting is a simple form of GC where each object keeps a count of how many pointers reference it.

## 🛠️ Implementation

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int ref_count;
    int data;
} Object;

Object* Object_Create(int value) {
    Object *obj = malloc(sizeof(Object));
    obj->ref_count = 1; // Start with 1 reference
    obj->data = value;
    return obj;
}

void Object_Retain(Object *obj) {
    obj->ref_count++;
}

void Object_Release(Object *obj) {
    obj->ref_count--;
    if (obj->ref_count == 0) {
        printf("Freeing Object %d\n", obj->data);
        free(obj);
    }
}

int main() {
    Object *o1 = Object_Create(42); // Ref: 1
    
    Object *o2 = o1;
    Object_Retain(o2); // Ref: 2
    
    Object_Release(o1); // Ref: 1
    Object_Release(o2); // Ref: 0 -> Freed!
    
    return 0;
}
```

## ⚠️ The Cycle Problem
If Object A points to Object B, and Object B points to Object A, their ref counts never reach 0. They leak.

---
[[00-Index|Back to GC Index]]
