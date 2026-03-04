# Loops (Iteration)

Loops execute a block of code as long as a specified condition is reached.

## 🔄 The `while` Loop
Loops through a block of code as long as a specified condition is true.

```c
int i = 0;
while (i < 5) {
  printf("%d\n", i);
  i++;
}
```

## 🔁 The `do...while` Loop
Guarantees execution at least once.

```c
int i = 0;
do {
  printf("%d\n", i);
  i++;
}
while (i < 5);
```

## 🔢 The `for` Loop
Ideal for iterating a specific number of times.

### Syntax
```c
for (initialization; condition; increment) {
  // code
}
```

### C Version Note
In **C89**, you cannot declare variables inside the `for` loop initialization. You must declare them before.

```c
/* C89 Style */
int i;
for (i = 0; i < 5; i++) { ... }

/* C99+ Style */
for (int i = 0; i < 5; i++) { ... }
```

## 🛑 Loop Control

### `break`
Exits the loop immediately.

```c
for (int i = 0; i < 10; i++) {
  if (i == 4) break; // Stops at 4
}
```

### `continue`
Skips the rest of the current iteration and jumps to the next one.

```c
for (int i = 0; i < 10; i++) {
  if (i == 4) continue; // Skips printing 4
  printf("%d\n", i);
}
```

---
[[00-Index|Back to Control Flow Index]]
