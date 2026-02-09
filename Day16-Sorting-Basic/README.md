# Day 16 — Sorting: Basic Algorithms

## 🎯 Mastery Goals
- Master bubble, selection, and insertion sort
- Understand sorting complexity analysis
- Implement stable and in-place sorting
- Recognize when to use each algorithm
- Build foundation for advanced sorting

---

## 1️⃣ Bubble Sort

**Concept:** Repeatedly swap adjacent elements if in wrong order.

```c
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        
        // Optimization: stop if no swaps made
        if (!swapped)
            break;
    }
}
```

**Visualization:**
```
[5, 2, 8, 1, 9]
[2, 5, 1, 8, 9]  // After pass 1
[2, 1, 5, 8, 9]  // After pass 2
[1, 2, 5, 8, 9]  // After pass 3 ✓
```

**Complexity:**
- Time: O(n²) average/worst, O(n) best (already sorted)
- Space: O(1)
- **Stable:** Yes
- **In-place:** Yes

---

## 2️⃣ Selection Sort

**Concept:** Select minimum element and place at beginning.

```c
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        
        // Find minimum in remaining array
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        
        // Swap minimum with current position
        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}
```

**Visualization:**
```
[64, 25, 12, 22, 11]
[11, 25, 12, 22, 64]  // Found min=11
[11, 12, 25, 22, 64]  // Found min=12
[11, 12, 22, 25, 64]  // Found min=22
[11, 12, 22, 25, 64]  // Sorted ✓
```

**Complexity:**
- Time: O(n²) all cases
- Space: O(1)
- **Stable:** No (can be made stable with extra space)
- **In-place:** Yes

---

## 3️⃣ Insertion Sort

**Concept:** Build sorted array one element at a time.

```c
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        
        // Move elements greater than key one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        
        arr[j + 1] = key;
    }
}
```

**Visualization:**
```
[5, 2, 4, 6, 1, 3]
[2, 5, 4, 6, 1, 3]  // Insert 2
[2, 4, 5, 6, 1, 3]  // Insert 4
[2, 4, 5, 6, 1, 3]  // 6 already in place
[1, 2, 4, 5, 6, 3]  // Insert 1
[1, 2, 3, 4, 5, 6]  // Insert 3 ✓
```

**Complexity:**
- Time: O(n²) average/worst, O(n) best (nearly sorted)
- Space: O(1)
- **Stable:** Yes
- **In-place:** Yes
- **Best for:** Small arrays, nearly sorted data

---

## 4️⃣ Comparison & When to Use

| Algorithm | Time (Avg) | Space | Stable | Best For |
|-----------|-----------|-------|--------|----------|
| Bubble | O(n²) | O(1) | Yes | Educational, nearly sorted |
| Selection | O(n²) | O(1) | No | Minimize swaps |
| Insertion | O(n²) | O(1) | Yes | Small/nearly sorted data |

---

## 5️⃣ Interview Problems

### Problem 1: Sort Array by Parity
Move all even numbers before odd numbers.

```c
void sortByParity(int arr[], int n) {
    int left = 0, right = n - 1;
    
    while (left < right) {
        if (arr[left] % 2 > arr[right] % 2) {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
        }
        
        if (arr[left] % 2 == 0) left++;
        if (arr[right] % 2 == 1) right--;
    }
}
```

### Problem 2: Sort Colors (Dutch National Flag)
Sort array with only 0s, 1s, and 2s.

```c
void sortColors(int arr[], int n) {
    int low = 0, mid = 0, high = n - 1;
    
    while (mid <= high) {
        if (arr[mid] == 0) {
            int temp = arr[low];
            arr[low++] = arr[mid];
            arr[mid++] = temp;
        } else if (arr[mid] == 1) {
            mid++;
        } else {
            int temp = arr[mid];
            arr[mid] = arr[high];
            arr[high--] = temp;
        }
    }
}
```

### Problem 3: Bubble Sort Count
Count swaps needed to sort array with bubble sort.

```c
int countSwaps(int arr[], int n) {
    int count = 0;
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                count++;
            }
        }
    }
    
    return count;
}
```

---

## 🧪 Practice Exercises

1. **Optimized Bubble Sort**: Implement with early termination
2. **Recursive Insertion Sort**: Write recursive version
3. **Stability Test**: Demonstrate why selection sort isn't stable
4. **Adaptive Sort**: Modify algorithm to detect sorted input

---

## 🎯 Interview Tips

✓ **Stability matters:** When sorting objects with multiple fields  
✓ **Insertion sort:** Excellent for small arrays (n < 10)  
✓ **Nearly sorted:** Insertion sort runs in O(n) time  
✓ **Minimize swaps:** Selection sort makes only O(n) swaps  

---

## 📚 Key Takeaways

- Basic sorts: O(n²) but simple and in-place
- Insertion sort: Best for small or nearly sorted arrays
- All three are stable except selection sort
- Foundation for understanding advanced sorting algorithms

---

**Next:** Day 17 - Advanced Sorting Algorithms
