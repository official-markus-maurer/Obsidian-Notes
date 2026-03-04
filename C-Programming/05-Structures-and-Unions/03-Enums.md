# Enumerations (enum)

An enumeration is a user-defined data type that consists of integral constants. To define an enumeration, keyword `enum` is used.

## 🏗️ Definition

```c
enum Weekday {Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday};
```

By default, the values start from 0 (`Sunday` = 0, `Monday` = 1, etc.).

## 🔧 Custom Values

You can assign specific values to enum names.

```c
enum State {Working = 1, Failed = 0, Freezed = 0};
```

## 📝 Usage

Enums make the code more readable.

```c
enum Weekday today = Wednesday;

if (today == Sunday || today == Saturday) {
    printf("Weekend!");
} else {
    printf("Weekday.");
}
```

---
[[00-Index|Back to Structs Index]]
