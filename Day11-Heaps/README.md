# Day 11 — Heaps

## 🎯 Mastery Goals
- Understand heap property and complete binary tree structure
- Master heapify, insert, and extract operations
- Implement heap sort algorithm
- Apply heaps to priority queue problems
- Recognize O(n) heap construction

---

## 1️⃣ What is a Heap?

A **heap** is a **complete binary tree** satisfying the **heap property**:

**Min-Heap:** Parent ≤ Children (root is minimum)
**Max-Heap:** Parent ≥ Children (root is maximum)

```text
Max-Heap Example:
        100
       /   \
     19     36
    /  \   /  \
   17   3  25  1

Every parent ≥ its children!
```

### Complete Binary Tree
- All levels filled except possibly last
- Last level filled from left to right
- **Can be efficiently stored in array!**

```text
Index:   0   1   2   3   4   5   6
Array: [100, 19, 36, 17, 3, 25, 1]
```

### Array Representation
```c
//  For node at index i:
// Left child  = 2*i + 1
// Right child = 2*i + 2
// Parent      = (i-1)/2
```

---

## 2️⃣ Heap Operations

### Heapify (Maintain Heap Property) — O(log n)
```c
void maxHeapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    // If left child is larger
    if (left < n && arr[left] > arr[largest])
        largest = left;
    
    // If right child is larger
    if (right < n && arr[right] > arr[largest])
        largest = right;
    
    // If largest is not root
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        maxHeapify(arr, n, largest);  // Recursively heapify
    }
}
```

### Build Heap — O(n) **Not O(n log n)!**
```c
void buildMaxHeap(int arr[], int n) {
    // Start from last non-leaf node and heapify all
    for (int i = (n / 2) - 1; i >= 0; i--) {
        maxHeapify(arr, n, i);
    }
}

// Why O(n)?
// Most nodes are at bottom (limited height)
// Mathematical analysis shows: Sum of (nodes at level h * h) = O(n)
```

### Insert — O(log n)
```c
void insertHeap(int arr[], int* n, int key) {
    // Increase heap size
    (*n)++;
    int i = (*n) - 1;
    arr[i] = key;
    
    // Fix the heap property (bubble up)
    while (i != 0 && arr[(i-1)/2] < arr[i]) {
        swap(&arr[i], &arr[(i-1)/2]);
        i = (i-1)/2;
    }
}
```

### Extract Max — O(log n)
```c
int extractMax(int arr[], int* n) {
    if (*n <= 0) return INT_MIN;
    if (*n == 1) {
        (*n)--;
        return arr[0];
    }
    
    // Store max and remove it
    int root = arr[0];
    arr[0] = arr[(*n) - 1];
    (*n)--;
    
    // Heapify the root
    maxHeapify(arr, *n, 0);
    
    return root;
}
```

---

## 3️⃣ Heap Sort — O(n log n)

```c
void heapSort(int arr[], int n) {
    // Build max heap - O(n)
    buildMaxHeap(arr, n);
    
    // Extract elements one by one - O(n log n)
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(&arr[0], &arr[i]);
        
        // Heapify reduced heap
        maxHeapify(arr, i, 0);
    }
}

// Time: O(n) + O(n log n) = O(n log n)
// Space: O(1) in-place sorting!
// Not stable, but guaranteed O(n log n) worst case
```

---

## 4️⃣ Common Heap Problems

### Problem 1: Find K Largest Elements
```c
// Using Min-Heap of size k
void kLargestElements(int arr[], int n, int k) {
    // Build min heap of first k elements
    int heap[k];
    for (int i = 0; i < k; i++)
        heap[i] = arr[i];
    buildMinHeap(heap, k);
    
    // Process remaining elements
    for (int i = k; i < n; i++) {
        if (arr[i] > heap[0]) {
            heap[0] = arr[i];
            minHeapify(heap, k, 0);
        }
    }
    
    // heap now contains k largest
    for (int i = 0; i < k; i++)
        printf("%d ", heap[i]);
}
// Time: O(n log k), Space: O(k)
```

### Problem 2: Merge K Sorted Arrays
```c
typedef struct {
    int value;
    int arrayIndex;
    int elementIndex;
} HeapNode;

void mergeKArrays(int arr[][N], int k) {
    HeapNode heap[k];
    
    // Insert first element of each array
    for (int i = 0; i < k; i++) {
        heap[i].value = arr[i][0];
        heap[i].arrayIndex = i;
        heap[i].elementIndex = 0;
    }
    buildMinHeap(heap, k);
    
    // Extract min and insert next from same array
    while (true) {
        HeapNode min = extractMin(heap);
        printf("%d ", min.value);
        
        int nextIdx = min.elementIndex + 1;
        if (nextIdx < N) {
            insertHeap(heap, arr[min.arrayIndex][nextIdx],
                      min.arrayIndex, nextIdx);
        }
    }
}
// Time: O(N*k * log k) where N is array size
```

### Problem 3: Running Median
```c
// Use two heaps: max-heap for smaller half, min-heap for larger half
typedef struct {
    int maxHeap[1000];  // Smaller half
    int minHeap[1000];  // Larger half
    int maxSize, minSize;
} MedianFinder;

void addNum(MedianFinder* mf, int num) {
    // Add to max heap (smaller half)
    if (mf->maxSize == 0 || num <= mf->maxHeap[0]) {
        insertMaxHeap(mf->maxHeap, &mf->maxSize, num);
    } else {
        insertMinHeap(mf->minHeap, &mf->minSize, num);
    }
    
    // Balance heaps (size difference ≤ 1)
    if (mf->maxSize > mf->minSize + 1) {
        int val = extractMax(mf->maxHeap, &mf->maxSize);
        insertMinHeap(mf->minHeap, &mf->minSize, val);
    } else if (mf->minSize > mf->maxSize) {
        int val = extractMin(mf->minHeap, &mf->minSize);
        insertMaxHeap(mf->maxHeap, &mf->maxSize, val);
    }
}

double findMedian(MedianFinder* mf) {
    if (mf->maxSize > mf->minSize)
        return mf->maxHeap[0];
    return (mf->maxHeap[0] + mf->minHeap[0]) / 2.0;
}
```

---

## 5️⃣ Min-Heap vs Max-Heap

**When to use:**
- **Max-Heap:** Find maximum, descending priority
- **Min-Heap:** Find minimum, ascending priority, Dijkstra's algorithm

**Conversion:** Negate all values to convert between types

---

## 🧪 Practice Exercises

### Exercise 1: Implement Min-Heap
Convert all max-heap operations to min-heap

### Exercise 2: Is Array a Heap?
Check if given array satisfies heap property

### Exercise 3: Kth Smallest Element
Similar to Kth largest, use max-heap

---

## 🎯 Interview Tips

✓ **Build heap:** O(n), not O(n log n)!  
✓ **Space efficient:** Array representation  
✓ **K largest/smallest:** Use heap of size k  
✓ **Running median:** Two heaps technique  

---

## 📚 Key Takeaways

- Heap: Complete binary tree with heap property
- Array implementation: parent (i-1)/2, children 2i+1, 2i+2
- Build heap: O(n), Insert/Extract: O(log n)
- Heap sort: O(n log n) time, O(1) space
- Essential for priority queues and efficient algorithms

---

**Next:** Day 12 - Priority Queues (abstract data type using heaps)
