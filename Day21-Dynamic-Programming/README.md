# Day 21 — Dynamic Programming

## 🎯 Mastery Goals

- Master dynamic programming fundamentals: memoization and tabulation
- Understand overlapping subproblems and optimal substructure
- Implement classic DP problems efficiently
- Recognize DP patterns in interview questions
- Optimize from recursion to iterative DP

---

## 1️⃣ What is Dynamic Programming?

**Dynamic Programming (DP)** is an optimization technique that solves complex problems by:

1. Breaking them into overlapping subproblems
2. Solving each subproblem once
3. Storing results to avoid recomputation

### Key Properties

- **Overlapping Subproblems:** Same subproblems solved multiple times
- **Optimal Substructure:** Optimal solution contains optimal solutions to subproblems

### Two Approaches

1. **Memoization (Top-Down):** Recursion + caching
2. **Tabulation (Bottom-Up):** Iterative, builds solution from base cases

---

## 2️⃣ Fibonacci — The Classic Example

### Naive Recursion — O(2ⁿ)

```c
int fib(int n) {
    if (n <= 1) return n;
    return fib(n-1) + fib(n-2);
}
```

### Memoization — O(n)

```c
int fibMemo(int n, int* memo) {
    if (n <= 1) return n;
    
    if (memo[n] != -1)
        return memo[n];
    
    memo[n] = fibMemo(n-1, memo) + fibMemo(n-2, memo);
    return memo[n];
}

int fibonacci(int n) {
    int* memo = (int*)malloc((n+1) * sizeof(int));
    for (int i = 0; i <= n; i++)
        memo[i] = -1;
    
    int result = fibMemo(n, memo);
    free(memo);
    return result;
}
```

### Tabulation — O(n)

```c
int fibTab(int n) {
    if (n <= 1) return n;
    
    int* dp = (int*)malloc((n+1) * sizeof(int));
    dp[0] = 0;
    dp[1] = 1;
    
    for (int i = 2; i <= n; i++)
        dp[i] = dp[i-1] + dp[i-2];
    
    int result = dp[n];
    free(dp);
    return result;
}
```

### Space Optimized — O(1)

```c
int fibOptimized(int n) {
    if (n <= 1) return n;
    
    int prev2 = 0, prev1 = 1;
    
    for (int i = 2; i <= n; i++) {
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    
    return prev1;
}
```

---

## 3️⃣ Common DP Patterns

### Pattern 1: 0/1 Knapsack

**Problem:** Maximize value with weight constraint.

```c
int knapsack(int weights[], int values[], int n, int capacity) {
    int** dp = (int**)malloc((n+1) * sizeof(int*));
    for (int i = 0; i <= n; i++)
        dp[i] = (int*)calloc(capacity+1, sizeof(int));
    
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= capacity; w++) {
            if (weights[i-1] <= w) {
                int include = values[i-1] + dp[i-1][w - weights[i-1]];
                int exclude = dp[i-1][w];
                dp[i][w] = (include > exclude) ? include : exclude;
            } else {
                dp[i][w] = dp[i-1][w];
            }
        }
    }
    
    int result = dp[n][capacity];
    
    for (int i = 0; i <= n; i++)
        free(dp[i]);
    free(dp);
    
    return result;
}
```

### Pattern 2: Longest Common Subsequence (LCS)

```c
int lcs(char* s1, char* s2, int m, int n) {
    int** dp = (int**)malloc((m+1) * sizeof(int*));
    for (int i = 0; i <= m; i++)
        dp[i] = (int*)calloc(n+1, sizeof(int));
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i-1] == s2[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = (dp[i-1][j] > dp[i][j-1]) ? dp[i-1][j] : dp[i][j-1];
        }
    }
    
    int result = dp[m][n];
    
    for (int i = 0; i <= m; i++)
        free(dp[i]);
    free(dp);
    
    return result;
}
```

### Pattern 3: Coin Change

```c
int coinChange(int coins[], int n, int amount) {
    int* dp = (int*)malloc((amount+1) * sizeof(int));
    
    for (int i = 0; i <= amount; i++)
        dp[i] = amount + 1;  // Initialize with max value
    
    dp[0] = 0;  // Base case
    
    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < n; j++) {
            if (coins[j] <= i) {
                int temp = dp[i - coins[j]] + 1;
                if (temp < dp[i])
                    dp[i] = temp;
            }
        }
    }
    
    int result = (dp[amount] > amount) ? -1 : dp[amount];
    free(dp);
    return result;
}
```

---

## 4️⃣ Interview Problems

### Problem 1: Climbing Stairs

Count ways to climb n stairs (1 or 2 steps at a time).

```c
int climbStairs(int n) {
    if (n <= 2) return n;
    
    int prev2 = 1, prev1 = 2;
    
    for (int i = 3; i <= n; i++) {
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    
    return prev1;
}
```

### Problem 2: House Robber

Maximize money robbed without robbing adjacent houses.

```c
int rob(int nums[], int n) {
    if (n == 0) return 0;
    if (n == 1) return nums[0];
    
    int prev2 = nums[0];
    int prev1 = (nums[0] > nums[1]) ? nums[0] : nums[1];
    
    for (int i = 2; i < n; i++) {
        int curr = (prev2 + nums[i] > prev1) ? prev2 + nums[i] : prev1;
        prev2 = prev1;
        prev1 = curr;
    }
    
    return prev1;
}
```

### Problem 3: Edit Distance

Minimum operations to convert string s1 to s2.

```c
int editDistance(char* s1, char* s2, int m, int n) {
    int** dp = (int**)malloc((m+1) * sizeof(int*));
    for (int i = 0; i <= m; i++)
        dp[i] = (int*)malloc((n+1) * sizeof(int));
    
    // Base cases
    for (int i = 0; i <= m; i++) dp[i][0] = i;
    for (int j = 0; j <= n; j++) dp[0][j] = j;
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            } else {
                int insert = dp[i][j-1];
                int delete = dp[i-1][j];
                int replace = dp[i-1][j-1];
                
                dp[i][j] = 1 + ((insert < delete) ? 
                               ((insert < replace) ? insert : replace) :
                               ((delete < replace) ? delete : replace));
            }
        }
    }
    
    int result = dp[m][n];
    
    for (int i = 0; i <= m; i++)
        free(dp[i]);
    free(dp);
    
    return result;
}
```

---

## 5️⃣ DP Problem-Solving Steps

### Step-by-Step Approach

1. **Identify DP:** Look for overlapping subproblems
2. **Define State:** What does dp[i] represent?
3. **Recurrence Relation:** How does dp[i] relate to previous states?
4. **Base Cases:** What are the smallest subproblems?
5. **Order of Computation:** Bottom-up or top-down?
6. **Space Optimization:** Can we reduce dimensions?

---

## 🧪 Practice Exercises

### Exercise 1: Longest Palindromic Subsequence

Find length of longest palindromic subsequence in a string.

### Exercise 2: Partition Equal Subset Sum

Determine if array can be partitioned into two equal sum subsets.

### Exercise 3: Matrix Chain Multiplication

Find minimum cost to multiply a chain of matrices.

### Exercise 4: Word Break

Check if string can be segmented into dictionary words.

---

## 🎯 Interview Tips

✓ **Start Simple:** Begin with recursive solution, then add memoization
✓ **State Definition:** Clearly define what each dp state represents
✓ **Recurrence:** Write out the mathematical recurrence relation
✓ **Base Cases:** Don't forget edge cases and initial values
✓ **Space Optimization:** After tabulation works, try reducing space
✓ **Common Patterns:** Knapsack, LCS, LIS, Grid paths, String matching

### Complexity Summary

| Pattern  | Time    | Space                     |
|----------|---------|---------------------------|
| 1D DP    | O(n)    | O(n) → O(1)               |
| 2D DP    | O(n²)   | O(n²) → O(n)              |
| Knapsack | O(n×W)  | O(W) optimized            |
| LCS      | O(m×n)  | O(min(m,n)) optimized     |

---

## 📚 Key Takeaways

- **DP = Recursion + Memoization:** Cache results of subproblems
- **Two approaches:** Top-down (recursive) vs Bottom-up (iterative)
- **Optimal substructure:** Solution contains optimal subsolutions
- **Overlapping subproblems:** Same calculations repeated
- **Space optimization:** Often possible to reduce dimensions
- **Practice patterns:** Recognize problem types (knapsack, LCS, etc.)

---

**Next:** Day 22 - Graph Representation
