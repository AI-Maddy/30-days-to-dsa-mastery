# Day 07 — Queues

## 🎯 Mastery Goals
- Understand FIFO (First In, First Out) principle
- Implement queue using array and linked list
- Master circular queue and deque
- Apply queues to BFS, task scheduling, and buffering problems
- Recognize queue patterns in interviews

---

## 1️⃣ What is a Queue?

A **queue** is a linear data structure following **FIFO** principle: first element added is first removed.

```text
  Rear                        Front
   ↓                            ↓
 ┌───┬───┬───┬───┐
 │ 4 │ 3 │ 2 │ 1 │  →  Dequeue from front
 └───┴───┴───┴───┘
   ↑
Enqueue here
```

### Core Operations
- **enqueue(x)** — Add to rear: O(1)
- **dequeue()** — Remove from front: O(1)
- **front()/peek()** — View front: O(1)
- **isEmpty()** — Check if empty: O(1)

---

## 2️⃣ Implementation: Array-Based (Circular)

```c
#define MAX 5

typedef struct {
    int arr[MAX];
    int front, rear;
    int size;
} Queue;

void initQueue(Queue* q) {
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

bool isEmpty(Queue* q) {
    return q->size == 0;
}

bool isFull(Queue* q) {
    return q->size == MAX;
}

void enqueue(Queue* q, int x) {
    if (isFull(q)) {
        printf("Queue Full!\n");
        return;
    }
    q->rear = (q->rear + 1) % MAX;  // Circular increment
    q->arr[q->rear] = x;
    q->size++;
}

int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue Empty!\n");
        return -1;
    }
    int data = q->arr[q->front];
    q->front = (q->front + 1) % MAX;  // Circular increment
    q->size--;
    return data;
}
```

---

## 3️⃣ Implementation: Linked List-Based

```c
typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node *front, *rear;
} Queue;

void initQueue(Queue* q) {
    q->front = q->rear = NULL;
}

void enqueue(Queue* q, int x) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = NULL;
    
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }
    
    q->rear->next = newNode;
    q->rear = newNode;
}

int dequeue(Queue* q) {
    if (q->front == NULL) {
        printf("Queue Empty!\n");
        return -1;
    }
    
    Node* temp = q->front;
    int data = temp->data;
    q->front = q->front->next;
    
    if (q->front == NULL)
        q->rear = NULL;
    
    free(temp);
    return data;
}
```

---

## 4️⃣ Circular Queue Advantage

**Linear Queue Problem:**
```text
After dequeue: [_, _, 3, 4]  front=2, rear=3
Can't enqueue even though space exists at beginning!
```

**Circular Queue Solution:**
```text
Use modulo: rear = (rear + 1) % MAX
Reuses space at beginning
```

---

## 5️⃣ Deque (Double-Ended Queue)

Operations at both ends

```c
void insertFront(Deque* dq, int x);
void insertRear(Deque* dq, int x);
int deleteFront(Deque* dq);
int deleteRear(Deque* dq);
```

**Applications:**
- Sliding window maximum/minimum
- Palindrome checking
- Undo/redo with restrictions

---

## 6️⃣ Queue Applications

### Application 1: BFS (Breadth-First Search)
```c
void BFS(Graph* g, int start) {
    Queue q;
    initQueue(&q);
    bool visited[MAX] = {false};
    
    enqueue(&q, start);
    visited[start] = true;
    
    while (!isEmpty(&q)) {
        int node = dequeue(&q);
        printf("%d ", node);
        
        // Enqueue all unvisited neighbors
        for (/* each neighbor */) {
            if (!visited[neighbor]) {
                enqueue(&q, neighbor);
                visited[neighbor] = true;
            }
        }
    }
}
```

### Application 2: Level Order Tree Traversal
```c
void levelOrder(TreeNode* root) {
    if (!root) return;
    
    Queue q;
    initQueue(&q);
    enqueue(&q, root);
    
    while (!isEmpty(&q)) {
        TreeNode* node = dequeue(&q);
        printf("%d ", node->data);
        
        if (node->left) enqueue(&q, node->left);
        if (node->right) enqueue(&q, node->right);
    }
}
```

### Application 3: Sliding Window Maximum
Using deque to track indices

---

## 🧪 Practice Exercises

### Exercise 1: Implement Stack using 2 Queues
Design stack using only queue operations

### Exercise 2: First Non-Repeating Character in Stream
Use queue + frequency array

### Exercise 3: Generate Binary Numbers
Generate binary numbers from 1 to n using queue

---

## 🎯 Interview Tips

✓ **Queue vs Stack:** FIFO vs LIFO  
✓ **Queue indicators:** BFS, level-order, task scheduling  
✓ **Circular queue:** Efficient space usage  
✓ **Deque:** Sliding window problems  

---

## 📚 Key Takeaways

- Queue: FIFO, O(1) operations
- Circular queue avoids wasted space
- Essential for BFS, level-order traversal
- Deque provides flexibility at both ends

---

**Next:** Day 08 - Recursion (function calls itself)
