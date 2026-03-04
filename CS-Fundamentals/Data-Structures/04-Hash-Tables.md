# Hash Tables

A Hash Table is a data structure that maps keys to values for highly efficient lookup. Ideally, the time complexity for insertion, deletion, and lookup is O(1).

## 🔑 Hash Function

A hash function takes an input (key) and returns an integer (index) within the range of the hash table size.

```c
unsigned int hash(char *key, int table_size) {
    unsigned int hash_val = 0;
    while (*key) {
        hash_val = (hash_val << 5) + *key++; // Simple hash
    }
    return hash_val % table_size;
}
```

## 💥 Collision Resolution

Collisions occur when two keys hash to the same index.

### 1. Chaining (Open Hashing)
Each bucket in the hash table points to a Linked List of entries.

```c
struct Entry {
    char *key;
    int value;
    struct Entry *next;
};

struct Entry *table[SIZE]; // Array of pointers
```

### 2. Open Addressing (Closed Hashing)
If a collision occurs, find the next open slot in the array (e.g., Linear Probing).

## 📝 Simple Implementation (Chaining)

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10

struct Node {
    int data;
    int key;
    struct Node *next;
};

struct Node *hashArray[SIZE];

int hashCode(int key) {
    return key % SIZE;
}

void insert(int key, int data) {
    struct Node *newItem = (struct Node*) malloc(sizeof(struct Node));
    newItem->data = data;
    newItem->key = key;
    newItem->next = NULL;

    int hashIndex = hashCode(key);

    if (hashArray[hashIndex] == NULL) {
        hashArray[hashIndex] = newItem;
    } else {
        // Add to front of list (collision)
        struct Node *current = hashArray[hashIndex];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newItem;
    }
}
```

---
[[00-Index|Back to Data Structures Index]]
