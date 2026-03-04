# Observer Pattern

The Observer pattern defines a one-to-many dependency between objects so that when one object changes state, all its dependents are notified and updated automatically.

## 🛠️ Implementation

We use function pointers to notify "observers".

```c
#include <stdio.h>

#define MAX_OBSERVERS 10

typedef void (*ObserverCallback)(int data);

typedef struct {
    ObserverCallback observers[MAX_OBSERVERS];
    int count;
    int state;
} Subject;

void RegisterObserver(Subject* s, ObserverCallback cb) {
    if (s->count < MAX_OBSERVERS) {
        s->observers[s->count++] = cb;
    }
}

void SetState(Subject* s, int data) {
    s->state = data;
    // Notify all
    for (int i = 0; i < s->count; i++) {
        s->observers[i](data);
    }
}

// Observers
void Listener1(int data) { printf("Listener 1 received: %d\n", data); }
void Listener2(int data) { printf("Listener 2 received: %d\n", data); }

int main() {
    Subject subj = {0};
    
    RegisterObserver(&subj, Listener1);
    RegisterObserver(&subj, Listener2);
    
    SetState(&subj, 42);
    
    return 0;
}
```

---
[[00-Index|Back to Design Patterns Index]]
