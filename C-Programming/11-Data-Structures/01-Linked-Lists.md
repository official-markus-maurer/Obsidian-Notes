# Linked Lists

A Linked List is a linear data structure where elements are not stored in contiguous memory locations. The elements are linked using pointers.

## 🔗 Singly Linked List

Each node contains:
1.  **Data**: The value.
2.  **Next**: A pointer to the next node.

```c
struct Node {
    int data;
    struct Node* next;
};
```

### Creating a Node

```c
#include <stdio.h>
#include <stdlib.h>

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) return NULL;
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
```

### Traversing

```c
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
```

## ⛓️ Doubly Linked List

Each node has pointers to both the **next** and **previous** nodes, allowing bidirectional traversal.

```c
struct DNode {
    int data;
    struct DNode* next;
    struct DNode* prev;
};
```

---
[[00-Index|Back to Data Structures Index]]
