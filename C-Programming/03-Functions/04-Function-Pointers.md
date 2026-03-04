# Function Pointers

A function pointer is a variable that stores the address of a function that can later be called through that function pointer. This is useful for **callbacks**, **event handlers**, and storing functions in arrays.

## 📝 Syntax

```c
return_type (*pointer_name)(parameter_types);
```

Example:
```c
int add(int a, int b) { return a + b; }

int (*func_ptr)(int, int) = &add; // or just = add
```

## 📞 Calling via Pointer

```c
int result = (*func_ptr)(10, 20); // Explicit dereference
int result2 = func_ptr(10, 20);   // Implicit (cleaner)
```

## 🔄 Callbacks

A callback is a function passed as an argument to another function.

```c
void operate(int a, int b, int (*operation)(int, int)) {
    printf("Result: %d\n", operation(a, b));
}

int main() {
    operate(5, 3, add);
    return 0;
}
```

## 📦 Array of Function Pointers

Useful for state machines or menu systems.

```c
int (*operations[4])(int, int) = {add, subtract, multiply, divide};
int result = operations[0](10, 5); // Calls add(10, 5)
```

## 🧹 typedef for Cleaner Syntax

Function pointer syntax can be messy. Use `typedef` to simplify.

```c
typedef int (*Operation)(int, int);

void operate(int a, int b, Operation op) {
    // ...
}
```

---
[[00-Index|Back to Functions Index]]
