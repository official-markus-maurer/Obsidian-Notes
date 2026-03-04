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
    
    printf("Initial State: Locked\n");
    
    printf("\nAction: Push\n");
    handle_event(&s, EVENT_PUSH); // Push failed
    
    printf("\nAction: Insert Coin\n");
    handle_event(&s, EVENT_COIN); // Unlocked
    
    printf("\nAction: Push\n");
    handle_event(&s, EVENT_PUSH); // Pushed. Locking
    
    return 0;
}
