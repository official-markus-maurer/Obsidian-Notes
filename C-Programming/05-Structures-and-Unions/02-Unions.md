# Unions

A union is a special data type available in C that allows to store different data types in the same memory location. You can define a union with many members, but only one member can contain a value at any given time.

## 🏗️ Definition

```c
union Data {
    int i;
    float f;
    char str[20];
};
```

## 💾 Memory Allocation
The memory occupied by a union is equal to the size of its largest member.

- `struct Data`: Size = `sizeof(int) + sizeof(float) + sizeof(char[20])` (approx. 28 bytes + padding)
- `union Data`: Size = `sizeof(char[20])` (20 bytes)

## ⚠️ Usage
Since all members share the same memory, changing one member will affect the others.

```c
union Data data;
data.i = 10;
printf("data.i: %d\n", data.i);

data.f = 220.5;
printf("data.f: %f\n", data.f);
printf("data.i: %d\n", data.i); // Garbage value!
```

---
[[00-Index|Back to Structs Index]]
