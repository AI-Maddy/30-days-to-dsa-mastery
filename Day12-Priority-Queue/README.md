# Day 12 — Priority Queues

## 🎯 Mastery Goals
- Understand priority queue abstract data type
- Implement using heaps efficiently  
- Master applications in algorithms (Dijkstra, Huffman, etc.)
- Solve priority-based scheduling problems
- Recognize when priority queue is the optimal data structure

---

## 1️⃣ What is a Priority Queue?

A **priority queue** is an abstract data type where each element has a **priority**. Elements with higher priority are served before elements with lower priority.

**Core Operations:**
- **insert(element, priority)** — Add element with priority: O(log n)
- **extractMax/extractMin()** — Remove highest/lowest priority: O(log n)
- **peek()** — View highest/lowest priority element: O(1)
- **changePriority()** — Update element's priority: O(log n)

```text
Real-World Examples:
┌─────────────────────────────────────┐
│ Emergency Room Triage               │
│ Critical → Urgent → Non-urgent      │
├─────────────────────────────────────┤
│ CPU Task Scheduling                 │
│ System → High → Normal → Low        │
├─────────────────────────────────────┤
│ Network Packet Routing              │
│ Express → Standard                  │
└─────────────────────────────────────┘
```

---

## 2️⃣ Implementation Using Binary Heap

**Why heap?** Perfect for priority queue!
- Extract max/min: O(log n)
- Insert: O(log n)
- Peek: O(1)
- Build: O(n)

```c
#define MAX 100

typedef struct {
    int data;
    int priority;
} PQElement;

typedef struct {
    PQElement heap[MAX];
    int size;
} PriorityQueue;

void initPQ(PriorityQueue* pq) {
    pq->size = 0;
}

// Swap helper
void swapPQElements(PQElement* a, PQElement* b) {
    PQElement temp = *a;
    *a = *b;
    *b = temp;
}

// Parent and child indices
int parent(int i) { return (i - 1) / 2; }
int leftChild(int i) { return 2 * i + 1; }
int rightChild(int i) { return 2 * i + 2; }
```

### Insert Operation — O(log n)
```c
void insert(PriorityQueue* pq, int data, int priority) {
    if (pq->size >= MAX) {
        printf("Priority Queue Full!\n");
        return;
    }
    
    // Add new element at end
    int i = pq->size;
    pq->heap[i].data = data;
    pq->heap[i].priority = priority;
    pq->size++;
    
    // Bubble up to maintain max-heap property
    while (i > 0 && pq->heap[parent(i)].priority < pq->heap[i].priority) {
        swapPQElements(&pq->heap[i], &pq->heap[parent(i)]);
        i = parent(i);
    }
}

// Visualization:
// Before insert(50): [100, 80, 60]
//        100
//       /   \
//      80    60
//
// After insert(90):
//        100
//       /   \
//      90    60
//     /
//    80
```

### Extract Max — O(log n)
```c
PQElement extractMax(PriorityQueue* pq) {
    if (pq->size == 0) {
        printf("Priority Queue Empty!\n");
        PQElement empty = {-1, -1};
        return empty;
    }
    
    PQElement max = pq->heap[0];
    
    // Move last element to root
    pq->heap[0] = pq->heap[pq->size - 1];
    pq->size--;
    
    // Heapify down from root
    int i = 0;
    while (true) {
        int largest = i;
        int left = leftChild(i);
        int right = rightChild(i);
        
        if (left < pq->size && 
            pq->heap[left].priority > pq->heap[largest].priority)
            largest = left;
        
        if (right < pq->size && 
            pq->heap[right].priority > pq->heap[largest].priority)
            largest = right;
        
        if (largest == i) break;
        
        swapPQElements(&pq->heap[i], &pq->heap[largest]);
        i = largest;
    }
    
    return max;
}
```

### Peek — O(1)
```c
PQElement peek(PriorityQueue* pq) {
    if (pq->size == 0) {
        PQElement empty = {-1, -1};
        return empty;
    }
    return pq->heap[0];
}

bool isEmpty(PriorityQueue* pq) {
    return pq->size == 0;
}

int getSize(PriorityQueue* pq) {
    return pq->size;
}
```

---

## 3️⃣ Common Applications

### Application 1: Task Scheduling (CPU)
```c
typedef struct {
    char name[50];
    int priority;  // Higher = more important
    int burstTime;
} Task;

void scheduleTasks(Task tasks[], int n) {
    PriorityQueue pq;
    initPQ(&pq);
    
    // Add all tasks to priority queue
    for (int i = 0; i < n; i++) {
        insert(&pq, i, tasks[i].priority);
    }
    
    printf("Execution Order:\n");
    while (!isEmpty(&pq)) {
        PQElement task = extractMax(&pq);
        printf("Task: %s (Priority: %d)\n", 
               tasks[task.data].name, 
               tasks[task.data].priority);
    }
}

// Example:
// Tasks: {("Email", 2), ("System Update", 5), ("Backup", 1)}
// Execution: System Update → Email → Backup
```

### Application 2: Merge K Sorted Lists
```c
typedef struct ListNode {
    int data;
    struct ListNode* next;
} ListNode;

typedef struct {
    ListNode* node;
    int listIndex;
} PQNode;

ListNode* mergeKSortedLists(ListNode* lists[], int k) {
    PriorityQueue pq;
    initPQ(&pq);
    
    // Insert first node from each list
    for (int i = 0; i < k; i++) {
        if (lists[i] != NULL) {
            // Use negative priority for min-heap behavior
            insert(&pq, (int)lists[i], -lists[i]->data);
        }
    }
    
    ListNode* dummy = (ListNode*)malloc(sizeof(ListNode));
    ListNode* tail = dummy;
    
    while (!isEmpty(&pq)) {
        PQElement minElem = extractMax(&pq);
        ListNode* minNode = (ListNode*)minElem.data;
        
        // Add to result
        tail->next = minNode;
        tail = tail->next;
        
        // If this list has more nodes, add next
        if (minNode->next != NULL) {
            insert(&pq, (int)minNode->next, -minNode->next->data);
        }
    }
    
    tail->next = NULL;
    return dummy->next;
}

// Time: O(N log k) where N = total nodes, k = number of lists
// Space: O(k) for priority queue
```

### Application 3: Huffman Encoding
```c
typedef struct HuffmanNode {
    char character;
    int frequency;
    struct HuffmanNode *left, *right;
} HuffmanNode;

HuffmanNode* buildHuffmanTree(char chars[], int freq[], int n) {
    PriorityQueue pq;
    initPQ(&pq);
    
    // Create leaf node for each character
    for (int i = 0; i < n; i++) {
        HuffmanNode* node = createHuffmanNode(chars[i], freq[i]);
        // Use negative frequency for min-heap
        insert(&pq, (int)node, -freq[i]);
    }
    
    // Build tree bottom-up
    while (pq.size > 1) {
        PQElement left = extractMax(&pq);
        PQElement right = extractMax(&pq);
        
        HuffmanNode* leftNode = (HuffmanNode*)left.data;
        HuffmanNode* rightNode = (HuffmanNode*)right.data;
        
        // Create internal node
        int combinedFreq = leftNode->frequency + rightNode->frequency;
        HuffmanNode* internal = createInternalNode(combinedFreq, 
                                                   leftNode, rightNode);
        
        insert(&pq, (int)internal, -combinedFreq);
    }
    
    return (HuffmanNode*)extractMax(&pq).data;
}
```

---

## 4️⃣ Advanced: Dijkstra's Algorithm with PQ

```c
#define INFINITY 999999

void dijkstra(int graph[MAX][MAX], int V, int src) {
    int dist[MAX];
    bool visited[MAX];
    
    // Initialize
    for (int i = 0; i < V; i++) {
        dist[i] = INFINITY;
        visited[i] = false;
    }
    dist[src] = 0;
    
    PriorityQueue pq;
    initPQ(&pq);
    insert(&pq, src, -0);  // Negative for min-heap behavior
    
    while (!isEmpty(&pq)) {
        PQElement u = extractMax(&pq);
        int node = u.data;
        
        if (visited[node]) continue;
        visited[node] = true;
        
        // Relax all adjacent vertices
        for (int v = 0; v < V; v++) {
            if (graph[node][v] && !visited[v]) {
                int newDist = dist[node] + graph[node][v];
                if (newDist < dist[v]) {
                    dist[v] = newDist;
                    insert(&pq, v, -newDist);
                }
            }
        }
    }
    
    // Print distances
    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < V; i++) {
        printf("%d\t%d\n", i, dist[i]);
    }
}

// Time: O((V + E) log V) with binary heap
// Can be improved to O(V log V + E) with Fibonacci heap
```

---

## 5️⃣ Interview Problems

### Problem 1: Kth Largest Element
```c
// Using min-heap of size k
int findKthLargest(int nums[], int n, int k) {
    PriorityQueue pq;  // Min-heap
    initPQ(&pq);
    
    // Add first k elements
    for (int i = 0; i < k; i++) {
        insert(&pq, nums[i], nums[i]);  // Priority = value for min-heap
    }
    
    // Process remaining elements
    for (int i = k; i < n; i++) {
        if (nums[i] > peek(&pq).priority) {
            extractMax(&pq);
            insert(&pq, nums[i], nums[i]);
        }
    }
    
    return peek(&pq).priority;
}
// Time: O(n log k), Space: O(k)
```

### Problem 2: Top K Frequent Elements
```c
int* topKFrequent(int nums[], int n, int k) {
    // Count frequencies using hash map
    int freq[1001] = {0};
    for (int i = 0; i < n; i++) {
        freq[nums[i]]++;
    }
    
    PriorityQueue pq;
    initPQ(&pq);
    
    // Add to min-heap of size k
    for (int i = 0; i < 1001; i++) {
        if (freq[i] > 0) {
            if (pq.size < k) {
                insert(&pq, i, freq[i]);
            } else if (freq[i] > peek(&pq).priority) {
                extractMax(&pq);
                insert(&pq, i, freq[i]);
            }
        }
    }
    
    int* result = (int*)malloc(k * sizeof(int));
    for (int i = 0; i < k; i++) {
        result[i] = extractMax(&pq).data;
    }
    return result;
}
```

### Problem 3: Meeting Rooms II
```c
// Minimum conference rooms needed
typedef struct {
    int start, end;
} Meeting;

int minMeetingRooms(Meeting meetings[], int n) {
    // Sort meetings by start time
    qsort(meetings, n, sizeof(Meeting), compareStart);
    
    PriorityQueue pq;  // Min-heap by end time
    initPQ(&pq);
    
    int maxRooms = 0;
    
    for (int i = 0; i < n; i++) {
        // Remove meetings that have ended
        while (!isEmpty(&pq) && peek(&pq).priority <= meetings[i].start) {
            extractMax(&pq);
        }
        
        // Add current meeting's end time
        insert(&pq, i, meetings[i].end);
        
        maxRooms = (pq.size > maxRooms) ? pq.size : maxRooms;
    }
    
    return maxRooms;
}
```

---

## 🧪 Practice Exercises

### Exercise 1: Kth Smallest Element in Stream
Design a class to find kth smallest element as new numbers are added

**Hint:** Use max-heap of size k

### Exercise 2: Process Tasks in Order
Given tasks with priorities and dependencies, execute in optimal order

### Exercise 3: Sliding Window Median
Find median of all subarrays of size k

**Hint:** Use two heaps (max-heap and min-heap)

---

## 🎯 Interview Tips

✓ **Heap choice:** K largest → min-heap, K smallest → max-heap  
✓ **Time complexity:** All operations O(log n), building O(n)  
✓ **Min-heap trick:** Negate priorities or use custom comparator  
✓ **Common with:** Dijkstra, Huffman, scheduling, K largest/smallest  
✓ **Alternative:** For small k, simple array can be O(k) each operation  

---

## 📚 Key Takeaways

- Priority queue: Abstract data type for priority-based operations
- Best implementation: Binary heap (O(log n) operations)
- Essential for: Dijkstra, A*, Huffman, task scheduling, streaming data
- K problems: Use heap of size k for O(n log k) solution
- Two-heap technique: For running median problems

---

**Next:** Day 13 - Hashing (O(1) average-case operations)
