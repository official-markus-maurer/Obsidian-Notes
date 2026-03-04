# Finite State Machines (FSM) in C

State machines are everywhere in C programming:
-   **Parsers**: Reading JSON, XML, or configuration files.
-   **Protocols**: Implementing TCP/IP, Bluetooth, or UART communication.
-   **UI Logic**: Handling button presses, menu navigation.
-   **Game Logic**: Character states (Idle -> Run -> Jump).

## Implementation Strategies
1.  [[01-Switch-FSM]]: The classic `switch-case` approach. Simple and readable for small machines.
2.  [[02-Table-Driven-FSM]]: Using function pointers in a lookup table. Scalable and cleaner for large machines.

## Why use an FSM?
-   **Clarity**: Defines distinct states and valid transitions.
-   **Predictability**: Easier to reason about complex logic.
-   **Debuggability**: You always know exactly what "state" the system is in.

---
[[../00-Start-Here|Back to Roadmap]] | [[01-Switch-FSM|Next: Switch-Case FSM]]
