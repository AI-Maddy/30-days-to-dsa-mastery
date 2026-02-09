# Day 02 — Arrays

## 🎯 Mastery Goals
- Understand contiguous memory allocation and cache locality
- Master array operations: access, insert, delete, search
- Learn essential array patterns for interviews
- Recognize when to use static vs dynamic arrays
- Solve common array problems efficiently

---

## 1️⃣ What is an Array?

An **array** is a collection of elements stored in **contiguous memory locations**.

```text
Memory Layout:
┌─────┬─────┬─────┬─────┬─────┐
│ a[0]│ a[1]│ a[2]│ a[3]│ a[4]│
└─────┴─────┴─────┴─────┴─────┘
  ↑
Base Address (1000)

Address of a[i] = Base + (i × sizeof(element))
Example: a[3] = 1000 + (3 × 4) = 1012 (for 4-byte integers)
```

---

## 2️⃣ Core Operations & Time Complexity

| Operation | Time | Space | Notes |
|-----------|------|-------|-------|
| **Access** `arr[i]` | O(1) | O(1) | Direct index calculation |
| **Search** (unsorted) | O(n) | O(1) | Must check each element |
| **Search** (sorted) | O(log n) | O(1) | Binary search |
| **Insert at end** | O(1)* | O(1) | Amortized for dynamic arrays |
| **Insert at pos i** | O(n) | O(1) | Must shift n-i elements right |
| **Delete at pos i** | O(n) | O(1) | Must shift elements left |
| **Update** `arr[i] = x` | O(1) | O(1) | Direct assignment |

*Amortized: occasional resize takes O(n), but rare

---

## 3️⃣ Static vs Dynamic Arrays

### Static Array (Fixed Size)
```c
int arr[100];  // Size must be known at compile time
```
- ✓ Fast allocation (stack)
- ✓ No overhead
- ✗ Fixed size
- ✗ Stack limited (~8MB)

### Dynamic Array (Heap Allocated)
```c
int* arr = (int*)malloc(n * sizeof(int));
```
- ✓ Flexible size
- ✓ Can allocate large arrays
- ✗ Manual memory management
- ✗ Slower allocation

---

## 4️⃣ Essential Array Patterns for Interviews

### Pattern 1: Two Pointers
Used for: Sorted arrays, pair sums, palindrome checking

**Example: Two Sum (Sorted Array)**
```c
// O(n) time, O(1) space
int* twoSum(int arr[], int n, int target) {
    int left = 0, right = n - 1;
    
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == target)
            return /* indices */;
        else if (sum < target)
            left++;
        else
            right--;
    }
    return NULL;
}
```

### Pattern 2: Sliding Window
Used for: Subarrays, substrings, sequences

**Example: Maximum Sum Subarray of Size k**
```c
// O(n) time, O(1) space
int maxSumSubarray(int arr[], int n, int k) {
    int windowSum = 0, maxSum = 0;
    
    // Initial window
    for (int i = 0; i < k; i++)
        windowSum += arr[i];
    maxSum = windowSum;
    
    // Slide window
    for (int i = k; i < n; i++) {
        windowSum += arr[i] - arr[i - k];
        maxSum = (windowSum > maxSum) ? windowSum : maxSum;
    }
    return maxSum;
}
```

### Pattern 3: Prefix Sum
Used for: Range sum queries

**Example: Range Sum Query**
```c
// Preprocessing: O(n), Query: O(1)
void buildPrefixSum(int arr[], int prefix[], int n) {
    prefix[0] = arr[0];
    for (int i = 1; i < n; i++)
        prefix[i] = prefix[i-1] + arr[i];
}

int rangeSum(int prefix[], int left, int right) {
    if (left == 0) return prefix[right];
    return prefix[right] - prefix[left - 1];
}
```

### Pattern 4: Kadane's Algorithm
Used for: Maximum subarray sum

```c
// O(n) time, O(1) space
int maxSubarraySum(int arr[], int n) {
    int maxSoFar = arr[0], maxEndingHere = arr[0];
    
    for (int i = 1; i < n; i++) {
        maxEndingHere = (arr[i] > maxEndingHere + arr[i]) ? 
                        arr[i] : maxEndingHere + arr[i];
        maxSoFar = (maxSoFar > maxEndingHere) ? 
                   maxSoFar : maxEndingHere;
    }
    return maxSoFar;
}
```

---

## 5️⃣ Common Interview Problems

### Problem 1: Rotate Array by k positions
```c
// Time: O(n), Space: O(1)
void reverse(int arr[], int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++; end--;
    }
}

void rotateArray(int arr[], int n, int k) {
    k = k % n;  // Handle k > n
    reverse(arr, 0, n - 1);      // Reverse entire array
    reverse(arr, 0, k - 1);      // Reverse first k
    reverse(arr, k, n - 1);      // Reverse rest
}
```

### Problem 2: Remove Duplicates from Sorted Array
```c
// Time: O(n), Space: O(1)
int removeDuplicates(int arr[], int n) {
    if (n == 0) return 0;
    
    int j = 0;  // Slow pointer
    for (int i = 1; i < n; i++) {  // Fast pointer
        if (arr[i] != arr[j]) {
            j++;
            arr[j] = arr[i];
        }
    }
    return j + 1;  // New length
}
```

### Problem 3: Move Zeros to End
```c
// Time: O(n), Space: O(1)
void moveZeros(int arr[], int n) {
    int j = 0;  // Position for next non-zero
    
    // Move non-zeros forward
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            arr[j++] = arr[i];
        }
    }
    
    // Fill rest with zeros
    while (j < n) {
        arr[j++] = 0;
    }
}
```

---

## 🧪 Practice Exercises

### Exercise 1: Find Missing Number
Array contains n-1 distinct numbers in range [0, n]. Find missing number.

**Hint:** Use sum formula or XOR

<details>
<summary>Solution</summary>

```c
// Using sum formula: O(n) time, O(1) space
int findMissing(int arr[], int n) {
    int totalSum = n * (n + 1) / 2;
    int arrSum = 0;
    for (int i = 0; i < n; i++)
        arrSum += arr[i];
    return totalSum - arrSum;
}
```
</details>

### Exercise 2: Best Time to Buy and Sell Stock
Find maximum profit from one transaction.

### Exercise 3: Container With Most Water

---

## 🎯 Interview Tips

✓ **Always ask:** Is array sorted? Duplicates allowed? Size constraints?  
✓ **Consider:** Two pointers, sliding window, prefix sums first  
✓ **Watch for:** Off-by-one errors, integer overflow  
✓ **Optimize:** Try to achieve O(n) time, O(1) space  

---

## 📚 Key Takeaways

- Arrays offer O(1) access but O(n) insertion/deletion
- Master two pointers and sliding window patterns
- Prefer in-place modifications to save space
- Cache locality makes arrays fast in practice

---

**Next:** Day 03 - Strings (character arrays with special properties)
