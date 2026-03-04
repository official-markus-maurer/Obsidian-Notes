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
This loop will execute the code block once, before checking if the condition is true, then it will repeat the loop as long as the condition is true.

```c
int i = 0;
do {
  printf("%d\n", i);
  i++;
}
while (i < 5);
```

## 🔢 The `for` Loop
When you know exactly how many times you want to loop through a block of code, use the `for` loop instead of a `while` loop.

```c
// syntax: for (initialization; condition; increment/decrement)
for (int i = 0; i < 5; i++) {
  printf("%d\n", i);
}
```

## 🛑 Loop Control

### `break`
Used to jump out of a loop completely.

```c
for (int i = 0; i < 10; i++) {
  if (i == 4) {
    break;
  }
  printf("%d\n", i);
}
```

### `continue`
Breaks one iteration (in the loop), if a specified condition occurs, and continues with the next iteration in the loop.

```c
for (int i = 0; i < 10; i++) {
  if (i == 4) {
    continue;
  }
  printf("%d\n", i);
}
```

---
[[00-Index|Back to Control Flow Index]]
