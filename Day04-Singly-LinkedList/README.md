# Day 04 — Singly Linked Lists

## 🎯 Mastery Goals
- Understand  pointer-based data structures
- Master linked list operations and traversal
- Handle edge cases (NULL, single node, etc.)
- Implement reversal, cycle detection, and merge operations
- Recognize when linked lists are better than arrays

---

## 1️⃣ What is a Linked List?

A **linked list** is a linear data structure where elements (nodes) are connected via **pointers**.

```text
┌──────┬────┐    ┌──────┬────┐    ┌──────┬────┐    ┌──────┬──────┐
│ Data │Next│───▶│ Data │Next│───▶│ Data │Next│───▶│ Data │ NULL │
└──────┴──  ──┘    └──────┴────┘    └──────┴────┘    └──────┴──────┘
  Head                                                    Tail
```

### Node Structure
```c
struct Node {
    int data;
    struct Node* next;
};
```

---

## 2️⃣ Linked List vs Array

| Feature | Array | Linked List |
|---------|-------|-------------|
| **Access** | O(1) | O(n) |
| **Insert at beginning** | O(n) | O(1) |
| **Insert at end** | O(1)* | O(n) or O(1) with tail |
| **Delete** | O(n) | O(1) if node given |
| **Memory** | Contiguous | Scattered |
| **Cache** | Cache-friendly | Cache-unfriendly |
| **Size** | Fixed (static) | Dynamic |

**Use linked lists when:**
- Frequent insertions/deletions at beginning
- Size unknown or changes frequently
- No random access needed

---

## 3️⃣ Core Operations

### Create Node
```c
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
```

### Insert at Beginning — O(1)
```c
void insertAtHead(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}
```

### Insert at End — O(n)
```c
void insertAtTail(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    
    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    
    temp->next = newNode;
}
```

### Delete Node — O(n)
```c
void deleteNode(struct Node** head, int key) {
    struct Node* temp = *head;
    struct Node* prev = NULL;
    
    // If head node holds the key
    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }
    
    // Search for the key
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    
    if (temp == NULL) return;  // Key not found
    
    prev->next = temp->next;
    free(temp);
}
```

### Traversal — O(n)
```c
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}
```

---

## 4️⃣ Essential Techniques

### Technique 1: Two Pointers (Slow & Fast)
Find middle element, detect cycles

```c
// Find middle: slow moves 1 step, fast moves 2 steps
struct Node* findMiddle(struct Node* head) {
    struct Node *slow = head, *fast = head;
    
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;  // Middle node
}
```

### Technique 2: Floyd's Cycle Detection
```c
bool hasCycle(struct Node* head) {
    struct Node *slow = head, *fast = head;
    
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        
        if (slow == fast)
            return true;  // Cycle detected
    }
    return false;
}
```

### Technique 3: Reverse Linked List — O(n)
```c
struct Node* reverse(struct Node* head) {
    struct Node *prev = NULL, *current = head, *next = NULL;
    
    while (current != NULL) {
        next = current->next;    // Save next
        current->next = prev;    // Reverse link
        prev = current;          // Move prev forward
        current = next;          // Move current forward
    }
    return prev;  // New head
}
```

**Visualization:**
```text
Original: 1 -> 2 -> 3 -> NULL

Step 1:  NULL <- 1    2 -> 3 -> NULL
         prev  curr  next

Step 2:  NULL <- 1 <- 2    3 -> NULL
                prev  curr next

Step 3:  NULL <- 1 <- 2 <- 3
                      prev curr
```

---

## 5️⃣ Advanced Problems

### Problem 1: Merge Two Sorted Lists
```c
struct Node* mergeSorted(struct Node* l1, struct Node* l2) {
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;
    
    if (l1->data <= l2->data) {
        l1->next = mergeSorted(l1->next, l2);
        return l1;
    } else {
        l2->next = mergeSorted(l1, l2->next);
        return l2;
    }
}
```

### Problem 2: Remove Nth Node from End
**Approach:** Use two pointers with n gap between them

```c
struct Node* removeNthFromEnd(struct Node* head, int n) {
    struct Node* dummy = createNode(0);
    dummy->next = head;
    struct Node *first = dummy, *second = dummy;
    
    // Move first n+1 steps ahead
    for (int i = 0; i <= n; i++)
        first = first->next;
    
    // Move both until first reaches end
    while (first != NULL) {
        first = first->next;
        second = second->next;
    }
    
    // Delete nth node from end
    struct Node* temp = second->next;
    second->next = second->next->next;
    free(temp);
    
    return dummy->next;
}
```

### Problem 3: Detect Cycle Starting Point
After detecting cycle with Floyd', find where cycle starts

---

## 🧪 Practice Exercises

### Exercise 1: Palindrome Linked List
Check if linked list is palindrome

**Hint:** Find middle, reverse second half, compare

### Exercise 2: Intersection of Two Lists
Find node where two lists intersect

### Exercise 3: Add Two Numbers
Add two numbers represented as linked lists

---

## 🎯 Interview Tips

✓ **Always handle:** NULL checks, single node, empty list  
✓ **Common technique:** Dummy node to simplify edge cases  
✓ **Draw diagrams:** Visualize pointer movements  
✓ **Count:** Track list length when needed  

---

## 📚 Key Takeaways

- Linked lists: dynamic, efficient insert/delete at beginning
- Master two-pointer technique (slow/fast)
- Practice reversal, cycle detection,  merging
- Always handle edge cases: NULL, single node

---

**Next:** Day 05 - Doubly & Circular Linked Lists
