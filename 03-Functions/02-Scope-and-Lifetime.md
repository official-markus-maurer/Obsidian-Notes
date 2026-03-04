# Scope and Lifetime

Scope refers to the visibility of variables, and lifetime refers to how long a variable exists in memory.

## 🏠 Local Variables
Declared inside a function or block.
- **Scope**: Only accessible within that function/block.
- **Lifetime**: Created when the function is called, destroyed when it exits.

```c
void func() {
    int x = 10; // Local to func
}
```

## 🌍 Global Variables
Declared outside of all functions (usually at the top of the file).
- **Scope**: Accessible by any function in the file.
- **Lifetime**: Exists for the entire duration of the program.

```c
int globalVar = 100;

void func() {
    printf("%d", globalVar); // Accessible here
}
```

## 🗿 Static Variables
Local variables that retain their value between function calls.
- **Scope**: Local to the function.
- **Lifetime**: Entire duration of the program.

```c
void counter() {
    static int count = 0; // Initialized only once
    count++;
    printf("%d\n", count);
}

int main() {
    counter(); // Output: 1
    counter(); // Output: 2
    counter(); // Output: 3
}
```

---
[[00-Index|Back to Functions Index]]
