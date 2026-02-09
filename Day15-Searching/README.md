# Day 15 — Searching Algorithms

## 🎯 Mastery Goals
- Master linear and binary search algorithms
- Understand search optimization techniques
- Implement various search variants efficiently
- Analyze time and space complexity
- Recognize when to apply each search algorithm

---

## 1️⃣ Linear Search

**Concept:** Search sequentially through elements until target is found.

```c
int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target)
            return i;  // Return index
    }
    return -1;  // Not found
}
```

**Complexity:**
- Time: O(n)
- Space: O(1)
- Best for: Small arrays, unsorted data

---

## 2️⃣ Binary Search

**Prerequisite:** Array must be sorted

```c
// Iterative Binary Search
int binarySearch(int arr[], int n, int target) {
    int left = 0, right = n - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;  // Avoid overflow
        
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    
    return -1;
}

// Recursive Binary Search
int binarySearchRecursive(int arr[], int left, int right, int target) {
    if (left > right)
        return -1;
    
    int mid = left + (right - left) / 2;
    
    if (arr[mid] == target)
        return mid;
    else if (arr[mid] < target)
        return binarySearchRecursive(arr, mid + 1, right, target);
    else
        return binarySearchRecursive(arr, left, mid - 1, target);
}
```

**Complexity:**
- Time: O(log n)
- Space: O(1) iterative, O(log n) recursive (call stack)

**Visualization:**
```
Array: [1, 3, 5, 7, 9, 11, 13, 15]  Target: 7

Step 1: [1, 3, 5, 7, 9, 11, 13, 15]
                  ^mid=9 > 7, search left

Step 2: [1, 3, 5, 7]
            ^mid=3 < 7, search right

Step 3: [5, 7]
         ^mid=5 < 7, search right

Step 4: [7]  ✓ Found!
```

---

## 3️⃣ Advanced Search Variants

### Jump Search
Optimized for sorted arrays, combines linear and binary search.

```c
int jumpSearch(int arr[], int n, int target) {
    int step = sqrt(n);
    int prev = 0;
    
    // Find block where element may be present
    while (arr[(step < n ? step : n) - 1] < target) {
        prev = step;
        step += sqrt(n);
        if (prev >= n)
            return -1;
    }
    
    // Linear search in identified block
    for (int i = prev; i < (step < n ? step : n); i++) {
        if (arr[i] == target)
            return i;
    }
    
    return -1;
}
```

**Complexity:** O(√n)

### Interpolation Search
Better for uniformly distributed data.

```c
int interpolationSearch(int arr[], int n, int target) {
    int low = 0, high = n - 1;
    
    while (low <= high && target >= arr[low] && target <= arr[high]) {
        if (low == high) {
            if (arr[low] == target) return low;
            return -1;
        }
        
        // Estimate position using interpolation formula
        int pos = low + ((target - arr[low]) * (high - low)) / 
                         (arr[high] - arr[low]);
        
        if (arr[pos] == target)
            return pos;
        else if (arr[pos] < target)
            low = pos + 1;
        else
            high = pos - 1;
    }
    
    return -1;
}
```

**Complexity:** O(log log n) for uniform data, O(n) worst case

### Exponential Search
Useful for unbounded or infinite arrays.

```c
int exponentialSearch(int arr[], int n, int target) {
    if (arr[0] == target)
        return 0;
    
    // Find range for binary search
    int i = 1;
    while (i < n && arr[i] <= target)
        i *= 2;
    
    // Binary search in found range
    return binarySearch(arr, i/2, (i < n ? i : n - 1), target);
}
```

---

## 4️⃣ Interview Problems

### Problem 1: First and Last Position
Find first and last occurrence of target in sorted array.

```c
int findFirst(int arr[], int n, int target) {
    int left = 0, right = n - 1;
    int result = -1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == target) {
            result = mid;
            right = mid - 1;  // Continue searching left
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return result;
}

int findLast(int arr[], int n, int target) {
    int left = 0, right = n - 1;
    int result = -1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == target) {
            result = mid;
            left = mid + 1;  // Continue searching right
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return result;
}
```

### Problem 2: Peak Element
Find peak element where arr[i] > arr[i-1] and arr[i] > arr[i+1].

```c
int findPeakElement(int arr[], int n) {
    int left = 0, right = n - 1;
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] > arr[mid + 1])
            right = mid;
        else
            left = mid + 1;
    }
    
    return left;
}
```

### Problem 3: Search in Rotated Sorted Array
```c
int searchRotated(int arr[], int n, int target) {
    int left = 0, right = n - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == target)
            return mid;
        
        // Left half is sorted
        if (arr[left] <= arr[mid]) {
            if (target >= arr[left] && target < arr[mid])
                right = mid - 1;
            else
                left = mid + 1;
        }
        // Right half is sorted
        else {
            if (target > arr[mid] && target <= arr[right])
                left = mid + 1;
            else
                right = mid - 1;
        }
    }
    
    return -1;
}
```

---

## 🧪 Practice Exercises

1. **Search Insert Position**: Find index where target should be inserted
2. **Square Root**: Implement integer square root using binary search
3. **Find Minimum in Rotated Sorted Array**
4. **Search in 2D Matrix**: Binary search on matrix

---

## 🎯 Interview Tips

✓ **Binary search template:** Master the while(left <= right) pattern  
✓ **Overflow prevention:** Use left + (right - left) / 2  
✓ **Edge cases:** Empty array, single element, not found  
✓ **Variants:** Know first/last occurrence, rotated arrays  

| Algorithm | Time | Space | Best For |
|-----------|------|-------|----------|
| Linear | O(n) | O(1) | Unsorted, small data |
| Binary | O(log n) | O(1) | Sorted data |
| Jump | O(√n) | O(1) | Sorted, large data |
| Interpolation | O(log log n) | O(1) | Uniformly distributed |

---

## 📚 Key Takeaways

- Binary search: Divide and conquer on sorted data
- Always check if data is sorted before using binary search
- Master the binary search template - many problems use variants
- Consider search algorithm based on data properties

---

**Next:** Day 16 - Basic Sorting Algorithms
