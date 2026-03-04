# Structures (struct)

A structure is a user-defined data type available in C that allows to combine data items of different kinds.

## 🏗️ Definition

```c
struct Person {
    char name[50];
    int age;
    float salary;
};
```

## 📝 Declaration and Initialization

### C89 Style
Positional initialization. Order matters.
```c
struct Person person2 = {"Bob", 25, 45000.0};
```

### C99 Designated Initializers
Initialize members by name. Order doesn't matter. Safer.
```c
struct Person person3 = {
    .age = 30,
    .name = "Alice",
    .salary = 50000.0
};
```

### C23 Zero Initialization
Initialize all members to zero/NULL.
```c
struct Person person4 = {}; 
```

## 📍 Accessing Members
- **Dot Operator (`.`)**: Used to access structure members via a structure variable.
- **Arrow Operator (`->`)**: Used to access structure members via a pointer to a structure.

```c
struct Person *ptr = &person1;

printf("Name: %s\n", person1.name);
printf("Age: %d\n", ptr->age); // Same as (*ptr).age
```

## 📦 Advanced Features

### Flexible Array Members (C99)
The last member of a struct can be an incomplete array. Useful for dynamic buffers.
```c
struct Buffer {
    int len;
    char data[]; // No size specified
};

// Allocate struct + data in one malloc
struct Buffer *b = malloc(sizeof(struct Buffer) + 100);
b->len = 100;
```

### Anonymous Structs (C11)
Members of an unnamed struct inside another struct can be accessed directly.
```c
struct Vector {
    struct { int x, y; }; // Anonymous
    int z;
};

struct Vector v;
v.x = 10; // Instead of v.inner.x
```

---
[[00-Index|Back to Structs Index]]
