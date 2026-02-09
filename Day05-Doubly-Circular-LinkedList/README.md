# Day 05 — Doubly & Circular Linked Lists

## 🎯 Mastery Goals
- Understand doubly linked list structure and advantages
- Master bidirectional traversal
- Learn circular linked list applications
- Implement deque using doubly linked list
- Compare singly, doubly, and circular variants

---

## 1️⃣ Doubly Linked List

Each node has **two pointers**: next and prev

```text
┌──────┬──────┬────┐    ┌──────┬──────┬────┐    ┌──────┬──────┬────┐
│ NULL │ Data │Next│───▶│ Prev │ Data │Next│───▶│ Prev │ Data │NULL│
└──────┴──────┴────┘    └──────┴──────┴────┘    └──────┴──────┴────┘
   Head                                              Tail
```

### Node Structure
```c
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};
```

---

## 2️⃣ Advantages Over Singly Linked List

| Feature | Singly | Doubly |
|---------|--------|--------|
| **Forward traversal** | ✓ | ✓ |
| **Backward traversal** | ✗ | ✓ |
| **Delete given node** | O(n) | O(1) |
| **Insert before node** | O(n) | O(1) |
| **Memory per node** | 1 pointer | 2 pointers |

**Use doubly linked lists when:**
- Need bidirectional traversal
- Frequent deletions with node reference
- Implementing LRU cache, browser history, etc.

---

## 3️⃣ Doubly Linked List Operations

### Insert at Beginning — O(1)
```c
void insertAtHead(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    
    if (*head != NULL) {
        (*head)->prev = newNode;
    }
    newNode->next = *head;
    *head = newNode;
}
```

### Delete a Specific Node — O(1)
```c
// Given direct reference to node (not key)
void deleteNode(struct Node** head, struct Node* del) {
    if (*head == NULL || del == NULL) return;
    
    // If node is head
    if (*head == del)
        *head = del->next;
    
    // Change next if node is not last
    if (del->next != NULL)
        del->next->prev = del->prev;
    
    // Change prev if node is not first
    if (del->prev != NULL)
        del->prev->next = del->next;
    
    free(del);
}
```

### Reverse Doubly Linked List
```c
struct Node* reverse(struct Node* head) {
    struct Node *temp = NULL, *current = head;
    
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    
    if (temp != NULL)
        head = temp->prev;
    
    return head;
}
```

---

## 4️⃣ Circular Linked List

Last node points back to first node (cycle by design)

```text
        ┌───────────────────────────┐
        │                           │
        ▼                           │
┌──────┬────┐    ┌──────┬────┐    ┌┴─────┬────┐
│ Data │Next│───▶│ Data │Next│───▶│ Data │Next│
└──────┴────┘    └──────┴────┘    └──────┴────┘
   Head
```

---

## 5️⃣ Applications

### Application 1: LRU Cache
- Use doubly linked list + hash map
- O(1) access, O(1) eviction

### Application 2: Browser History
- Forward/backward buttons
- Current page tracking

### Application 3: Music Playlist
- Circular list for continuous play
- Next/previous song

---

## 🧪 Practice Exercises

### Exercise 1: Rotate Doubly Linked List
Given a doubly linked list, rotate it by k nodes

### Exercise 2: Flatten Multilevel Doubly Linked List
Handle nodes with child pointers

### Exercise 3: Clone List with Random Pointer
Deep copy with random pointers

---

## 📚 Key Takeaways

- Doubly linked lists: bidirectional, faster deletions
- Extra memory cost (2 pointers vs 1)
- Circular lists: no NULL, useful for round-robin
- Choose variant based on access patterns

---

**Next:** Day 06 - Stacks (LIFO data structure)
