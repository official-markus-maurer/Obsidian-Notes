# Conditional Statements

## ❓ The `if` Statement
Executes a block of code only if a specified condition is true.

```c
if (condition) {
  // block of code to be executed if the condition is true
}
```

## 🛤️ The `if...else` Statement
Executes one block of code if the condition is true and another block if it is false.

```c
int time = 20;
if (time < 18) {
  printf("Good day.");
} else {
  printf("Good evening.");
}
```

## 🪜 The `else if` Ladder
Used to specify a new condition if the first condition is false.

```c
int time = 22;
if (time < 10) {
  printf("Good morning.");
} else if (time < 20) {
  printf("Good day.");
} else {
  printf("Good evening.");
}
```

## 🔀 The `switch` Statement
Selects one of many code blocks to be executed. It's often cleaner than many `else if` statements when checking a single variable against multiple constant values.

```c
int day = 4;
switch (day) {
  case 1:
    printf("Monday");
    break; // Break prevents fall-through to the next case
  case 2:
    printf("Tuesday");
    break;
  case 3:
    printf("Wednesday");
    break;
  case 4:
    printf("Thursday");
    break;
  case 5:
    printf("Friday");
    break;
  case 6:
    printf("Saturday");
    break;
  case 7:
    printf("Sunday");
    break;
  default: // Executed if no cases match
    printf("Looking forward to the Weekend");
}
```

---
[[00-Index|Back to Control Flow Index]]
