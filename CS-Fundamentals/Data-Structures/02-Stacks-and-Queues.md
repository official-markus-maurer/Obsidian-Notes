# Stacks and Queues

## 📚 Stack (LIFO - Last In First Out)

Think of a stack of plates. You add to the top (`push`) and remove from the top (`pop`).

### Implementation (Using Array)

```c
#define MAX 100
int stack[MAX];
int top = -1;

void push(int val) {
    if (top >= MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = val;
    }
}

int pop() {
    if (top < 0) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        return stack[top--];
    }
}
```

## 🚶 Queue (FIFO - First In First Out)

Think of a line at a store. You join at the back (`enqueue`) and leave from the front (`dequeue`).

### Implementation (Using Linked List)

```c
struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node *front, *rear;
};

void enqueue(struct Queue* q, int val) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->next = NULL;
    
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    
    q->rear->next = temp;
    q->rear = temp;
}

int dequeue(struct Queue* q) {
    if (q->front == NULL) return -1;
    
    struct Node* temp = q->front;
    int data = temp->data;
    q->front = q->front->next;
    
    if (q->front == NULL) q->rear = NULL;
    
    free(temp);
    return data;
}
```

---
[[00-Index|Back to Data Structures Index]]
