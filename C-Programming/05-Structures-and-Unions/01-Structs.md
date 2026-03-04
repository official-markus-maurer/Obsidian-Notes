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

```c
struct Person person1; // Declaration
strcpy(person1.name, "Alice");
person1.age = 30;
person1.salary = 50000.0;

// Initialization at declaration
struct Person person2 = {"Bob", 25, 45000.0};
```

## 📍 Accessing Members
- **Dot Operator (`.`)**: Used to access structure members via a structure variable.
- **Arrow Operator (`->`)**: Used to access structure members via a pointer to a structure.

```c
struct Person *ptr = &person1;

printf("Name: %s\n", person1.name);
printf("Age: %d\n", ptr->age); // Same as (*ptr).age
```

## 📦 Array of Structures

```c
struct Person employees[100];
employees[0].age = 22;
```

---
[[00-Index|Back to Structs Index]]
