# Factory Pattern

The Factory pattern provides a way to create objects without exposing the creation logic to the client.

## 🛠️ Implementation

We can use an `enum` to specify the type and a function that returns a `void*` or a base struct pointer.

```c
#include <stdio.h>
#include <stdlib.h>

typedef enum {
    SHAPE_CIRCLE,
    SHAPE_SQUARE
} ShapeType;

typedef struct {
    ShapeType type;
    void (*draw)(void*);
} Shape;

// Concrete implementations
void drawCircle(void* s) { printf("Drawing Circle\n"); }
void drawSquare(void* s) { printf("Drawing Square\n"); }

// Factory Function
Shape* CreateShape(ShapeType type) {
    Shape* s = (Shape*)malloc(sizeof(Shape));
    s->type = type;
    
    if (type == SHAPE_CIRCLE) {
        s->draw = drawCircle;
    } else if (type == SHAPE_SQUARE) {
        s->draw = drawSquare;
    }
    
    return s;
}

int main() {
    Shape* s1 = CreateShape(SHAPE_CIRCLE);
    Shape* s2 = CreateShape(SHAPE_SQUARE);
    
    s1->draw(s1);
    s2->draw(s2);
    
    free(s1);
    free(s2);
    return 0;
}
```

---
[[00-Index|Back to Design Patterns Index]]
