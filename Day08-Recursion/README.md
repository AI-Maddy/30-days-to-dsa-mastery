# Day 08 — Recursion

## 🎯 Mastery Goals
- Understand recursive function calls and base cases
- Master recursion tree visualization
- Learn tail recursion optimization
- Apply recursion to divide-and-conquer problems
- Recognize when recursion is appropriate vs iterative solutions

---

## 1️⃣ What is Recursion?

**Recursion** is when a function calls itself to solve smaller instances of the same problem.

```c
int factorial(int n) {
    if (n <= 1)           // Base case
        return 1;
    return n * factorial(n - 1);  // Recursive case
}
```

### Recursion Requirements
1. **Base Case** — Stopping condition
2. **Recursive Case** — Problem reduced toward base case
3. **Progress** — Each call moves toward base case

---

## 2️⃣ How Recursion Works (Call Stack)

```c
factorial(3):
  3 * factorial(2):
        2 * factorial(1):
              1 * factorial(0):
                    return 1
              return 1
        return 2
  return 6
```

**Call Stack:**
```text
factorial(3)   ← Waiting for factorial(2)
factorial(2)   ← Waiting for factorial(1)
factorial(1)   ← Waiting for factorial(0)
factorial(0)   ← Returns 1
```

---

## 3️⃣ Types of Recursion

### Type 1: Linear Recursion (One Call)
```c
int sum(int n) {
    if (n == 0) return 0;
    return n + sum(n - 1);
}
// Time: O(n), Space: O(n) stack
```

### Type 2: Binary Recursion (Two Calls)
```c
int fib(int n) {
    if (n <= 1) return n;
    return fib(n-1) + fib(n-2);  // Two recursive calls!
}
// Time: O(2^n), Space: O(n) max depth
```

### Type 3: Tail Recursion (Last Operation is Recursive Call)
```c
int factorial_tail(int n, int acc) {
    if (n <= 1) return acc;
    return factorial_tail(n - 1, n * acc);  // Tail recursive
}
// Can be optimized to O(1) space by compiler
```

### Type 4: Indirect Recursion
```c
void funA(int n) {
    if (n > 0) {
        printf("%d ", n);
        funB(n - 1);
    }
}

void funB(int n) {
    if (n > 1) {
        printf("%d ", n);
        funA(n / 2);
    }
}
```

---

## 4️⃣ Common Recursive Patterns

### Pattern 1: Divide and Conquer
```c
// Binary Search
int binarySearch(int arr[], int left, int right, int target) {
    if (left > right) return -1;  // Base case
    
    int mid = left + (right - left) / 2;
    if (arr[mid] == target) return mid;
    
    if (arr[mid] > target)
        return binarySearch(arr, left, mid - 1, target);
    else
        return binarySearch(arr, mid + 1, right, target);
}
// Time: O(log n), Space: O(log n)
```

### Pattern 2: Backtracking
```c
// Generate all subsets
void generateSubsets(int arr[], int n, int index, int* subset, int size) {
    if (index == n) {
        printSubset(subset, size);
        return;
    }
    
    // Exclude current element
    generateSubsets(arr, n, index + 1, subset, size);
    
    // Include current element
    subset[size] = arr[index];
    generateSubsets(arr, n, index + 1, subset, size + 1);
}
```

### Pattern 3: Tree Recursion
```c
// Tree traversals
void inorder(TreeNode* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
```

---

## 5️⃣ Recursion vs Iteration

| Aspect | Recursion | Iteration |
|--------|-----------|-----------|
| **Code** | Often cleaner | Can be verbose |
| **Space** | O(depth) stack | O(1) typically |
| **Performance** | Function call overhead | Faster |
| **Problems** | Trees, graphs, backtracking | Loops, sequences |

**Use recursion when:**
- Problem naturally recursive (trees, graphs)
- Divide and conquer
- Backtracking
- Code clarity matters more than performance

**Use iteration when:**
- Simple loops
- Performance critical
- Stack space limited

---

## 6️⃣ Optimizing Recursion: Memoization

**Problem:** Fibonacci has overlapping subproblems
```c
// Naive: O(2^n)
int fib(int n) {
    if (n <= 1) return n;
    return fib(n-1) + fib(n-2);
}
```

**Solution:** Memoization (Top-Down DP)
```c
// Optimized: O(n)
int fib_memo(int n, int* memo) {
    if (n <= 1) return n;
    
    if (memo[n] != -1)  // Already computed
        return memo[n];
    
    memo[n] = fib_memo(n-1, memo) + fib_memo(n-2, memo);
    return memo[n];
}

// Usage:
int memo[100];
memset(memo, -1, sizeof(memo));
int result = fib_memo(n, memo);
```

---

## 7️⃣ Common Pitfalls

### Pitfall 1: Missing Base Case
```c
// Infinite recursion!
int bad(int n) {
    return n + bad(n - 1);  // Never stops
}
```

### Pitfall 2: Not Progressing Toward Base Case
```c
// Infinite recursion!
int bad(int n) {
    if (n == 0) return 0;
    return bad(n);  // n doesn't change!
}
```

### Pitfall 3: Stack Overflow
```c
// Deep recursion can overflow stack
factorial(1000000);  // Likely stack overflow
```

---

## 🧪 Practice Exercises

### Exercise 1: Tower of Hanoi
Move n disks from source to destination using auxiliary peg

**Hint:** Move n-1 to auxiliary, move largest to destination, move n-1 to destination

### Exercise 2: Generate All Permutations
Given array, generate all permutations

### Exercise 3: Power Function
Compute x^n efficiently using recursion

**Hint:** x^n = x^(n/2) * x^(n/2) for even n

---

## 🎯 Interview Tips

✓ **Always identify:** Base case and recursive case  
✓ **Draw recursion tree:** Visualize calls  
✓ **Check complexity:** Time and space (stack)  
✓ **Consider iterative:** If stack space is issue  
✓ **Memoize:** If overlapping subproblems  

---

## 📚 Key Takeaways

- Recursion: function calls itself
- Requires base case and progress toward it
- Space: O(depth) for call stack
- Optimize with memoization for overlapping subproblems
- Choose recursion for naturally recursive problems

---

**Next:** Day 09 - Binary Trees (hierarchical data structure)
