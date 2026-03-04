# Table-Driven State Machine

For complex state machines, a table of function pointers is cleaner. It separates the **transition logic** from the **state actions**.

## Structure
We define a 2D array (table) where:
-   Rows = Current State
-   Columns = Event
-   Value = Function to call (Action) and Next State.

## Example: Advanced Parser

```c
#include <stdio.h>

// 1. Define States and Events
typedef enum {
    STATE_IDLE,
    STATE_READING,
    STATE_ERROR,
    STATE_MAX
} State;

typedef enum {
    EVENT_START,
    EVENT_DATA,
    EVENT_STOP,
    EVENT_MAX
} Event;

// 2. Define Function Pointer Type
typedef void (*ActionFunc)(void);

// 3. Define Transition Structure
typedef struct {
    State next_state;
    ActionFunc action;
} Transition;

// 4. Implement Actions
void action_start() { printf("Starting...\n"); }
void action_read()  { printf("Reading data...\n"); }
void action_stop()  { printf("Stopping...\n"); }
void action_error() { printf("Error occurred!\n"); }

// 5. Define the State Table
// [Current State][Event] -> {Next State, Action}
Transition transition_table[STATE_MAX][EVENT_MAX] = {
    [STATE_IDLE] = {
        [EVENT_START] = {STATE_READING, action_start},
        [EVENT_DATA]  = {STATE_IDLE,    NULL},         // Ignore
        [EVENT_STOP]  = {STATE_IDLE,    NULL}          // Ignore
    },
    [STATE_READING] = {
        [EVENT_START] = {STATE_ERROR,   action_error}, // Unexpected
        [EVENT_DATA]  = {STATE_READING, action_read},
        [EVENT_STOP]  = {STATE_IDLE,    action_stop}
    },
    [STATE_ERROR] = {
        [EVENT_START] = {STATE_IDLE,    NULL},         // Reset
        [EVENT_DATA]  = {STATE_ERROR,   NULL},
        [EVENT_STOP]  = {STATE_ERROR,   NULL}
    }
};

// 6. The Engine
void process_event(State *current_state, Event event) {
    if (event >= EVENT_MAX || *current_state >= STATE_MAX) return;

    Transition t = transition_table[*current_state][event];
    
    // Execute action if present
    if (t.action) {
        t.action();
    }
    
    // Update state
    *current_state = t.next_state;
}

int main() {
    State s = STATE_IDLE;
    
    process_event(&s, EVENT_START); // Starting... (State -> READING)
    process_event(&s, EVENT_DATA);  // Reading data... (State -> READING)
    process_event(&s, EVENT_STOP);  // Stopping... (State -> IDLE)
    
    return 0;
}
```

## Pros
-   **O(1) Access**: Constant time transition lookup.
-   **Clean Separation**: Actions are isolated functions.
-   **Scalable**: Adding a new state just adds a row to the table.

## Cons
-   **Sparse Tables**: If many transitions are invalid, the table wastes space.
-   **Complex Setup**: Requires careful struct and array initialization.

---
[[00-Index|Back to Index]] | [[../Resources/00-Index|Resources]]
