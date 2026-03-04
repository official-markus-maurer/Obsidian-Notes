# Switch-Case State Machine

The simplest way to implement a Finite State Machine in C is using an `enum` for states and a `switch` statement inside a loop.

## Example: Simple Turnstile
A turnstile has two states: `LOCKED` and `UNLOCKED`.
-   **Push** while Locked -> Stay Locked.
-   **Coin** while Locked -> Unlock.
-   **Push** while Unlocked -> Lock.
-   **Coin** while Unlocked -> Stay Unlocked.

```c
#include <stdio.h>

typedef enum {
    STATE_LOCKED,
    STATE_UNLOCKED
} State;

typedef enum {
    EVENT_COIN,
    EVENT_PUSH
} Event;

void handle_event(State *current_state, Event event) {
    switch (*current_state) {
        case STATE_LOCKED:
            if (event == EVENT_COIN) {
                *current_state = STATE_UNLOCKED;
                printf("Coin inserted. Unlocking.\n");
            } else if (event == EVENT_PUSH) {
                printf("Push failed. Locked.\n");
            }
            break;
            
        case STATE_UNLOCKED:
            if (event == EVENT_COIN) {
                printf("Coin returned. Already unlocked.\n");
            } else if (event == EVENT_PUSH) {
                *current_state = STATE_LOCKED;
                printf("Pushed. Locking.\n");
            }
            break;
    }
}

int main() {
    State s = STATE_LOCKED;
    
    handle_event(&s, EVENT_PUSH); // Push failed
    handle_event(&s, EVENT_COIN); // Unlocked
    handle_event(&s, EVENT_PUSH); // Pushed. Locking
    
    return 0;
}
```

## Pros
-   Easy to understand.
-   No dynamic memory or complex pointers.
-   Compiler can optimize jump tables.

## Cons
-   Gets messy with many states (spaghetti code).
-   Logic for transitions is mixed with state actions.

---
[[00-Index|Back to Index]] | [[02-Table-Driven-FSM|Next: Table-Driven FSM]]
