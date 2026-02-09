# Day 30 — Final Revision & Mock Test

## 🎯 Mastery Goals

- Review all 30 days of DSA concepts
- Practice mixed problems combining multiple topics
- Simulate real interview conditions
- Build confidence for technical interviews
- Master problem-solving strategies

---

## 1️⃣ Key Concepts Review

### Data Structures Covered

- **Linear:** Arrays, Strings, Linked Lists, Stacks, Queues
- **Trees:** Binary Trees, BST, Heaps, Tries
- **Graphs:** Representations, Traversals, Shortest Paths, MST
- **Hashing:** Hash Tables, Hash Maps, Sets

### Algorithms Covered

- **Searching:** Linear, Binary, Advanced variants
- **Sorting:** Bubble, Selection, Insertion, Merge, Quick, Heap
- **Recursion & Backtracking:** Problem solving patterns
- **Greedy:** Optimization problems
- **Divide & Conquer:** Breaking down problems
- **Dynamic Programming:** Memoization & Tabulation

---

## 2️⃣ Problem-Solving Framework

### The UPER Method

1. **Understand:** Clarify the problem
   - Read carefully
   - Ask clarifying questions
   - Identify inputs/outputs
   - Note constraints

2. **Plan:** Design your approach
   - Think of brute force first
   - Identify patterns
   - Choose data structures
   - Outline algorithm steps

3. **Execute:** Implement the solution
   - Write clean code
   - Use meaningful variable names
   - Add comments for complex logic
   - Handle edge cases

4. **Reflect:** Test and optimize
   - Test with examples
   - Check edge cases
   - Analyze complexity
   - Optimize if needed

---

## 3️⃣ Common Interview Patterns

### Pattern 1: Two Pointers

```c
// Remove duplicates from sorted array
int removeDuplicates(int arr[], int n) {
    if (n <= 1) return n;
    
    int i = 0;
    for (int j = 1; j < n; j++) {
        if (arr[j] != arr[i]) {
            i++;
            arr[i] = arr[j];
        }
    }
    
    return i + 1;
}
```

### Pattern 2: Sliding Window

```c
// Maximum sum subarray of size k
int maxSumSubarray(int arr[], int n, int k) {
    if (n < k) return -1;
    
    int windowSum = 0;
    for (int i = 0; i < k; i++)
        windowSum += arr[i];
    
    int maxSum = windowSum;
    
    for (int i = k; i < n; i++) {
        windowSum = windowSum - arr[i-k] + arr[i];
        if (windowSum > maxSum)
            maxSum = windowSum;
    }
    
    return maxSum;
}
```

### Pattern 3: Fast & Slow Pointers

```c
// Detect cycle in linked list
bool hasCycle(Node* head) {
    if (!head || !head->next) return false;
    
    Node* slow = head;
    Node* fast = head->next;
    
    while (slow != fast) {
        if (!fast || !fast->next)
            return false;
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return true;
}
```

---

## 4️⃣ Mock Interview Problems

### Problem 1: Array Manipulation

#### Rotate array right by k steps

```c
void reverse(int arr[], int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void rotateArray(int arr[], int n, int k) {
    k = k % n;
    if (k == 0) return;
    
    reverse(arr, 0, n-1);      // Reverse entire array
    reverse(arr, 0, k-1);      // Reverse first k elements
    reverse(arr, k, n-1);      // Reverse remaining elements
}
// Time: O(n), Space: O(1)
```

### Problem 2: String Processing

#### Find first non-repeating character

```c
char firstNonRepeating(char* str) {
    int freq[256] = {0};
    
    // Count frequencies
    for (int i = 0; str[i]; i++)
        freq[(int)str[i]]++;
    
    // Find first with frequency 1
    for (int i = 0; str[i]; i++) {
        if (freq[(int)str[i]] == 1)
            return str[i];
    }
    
    return '\0';
}
// Time: O(n), Space: O(1)
```

### Problem 3: Tree Traversal

#### Level order traversal (BFS)

```c
void levelOrder(TreeNode* root) {
    if (!root) return;
    
    TreeNode* queue[1000];
    int front = 0, rear = 0;
    
    queue[rear++] = root;
    
    while (front < rear) {
        TreeNode* current = queue[front++];
        printf("%d ", current->data);
        
        if (current->left)
            queue[rear++] = current->left;
        if (current->right)
            queue[rear++] = current->right;
    }
}
// Time: O(n), Space: O(w) where w is max width
```

### Problem 4: Dynamic Programming

#### Longest increasing subsequence

```c
int lengthOfLIS(int arr[], int n) {
    int* dp = (int*)malloc(n * sizeof(int));
    
    for (int i = 0; i < n; i++)
        dp[i] = 1;
    
    int maxLen = 1;
    
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                if (dp[i] > maxLen)
                    maxLen = dp[i];
            }
        }
    }
    
    free(dp);
    return maxLen;
}
// Time: O(n²), Space: O(n)
```

### Problem 5: Graph Problem

#### Number of islands (DFS)

```c
void dfs(char grid[][100], int rows, int cols, int i, int j) {
    if (i < 0 || i >= rows || j < 0 || j >= cols || grid[i][j] == '0')
        return;
    
    grid[i][j] = '0';  // Mark as visited
    
    dfs(grid, rows, cols, i+1, j);  // Down
    dfs(grid, rows, cols, i-1, j);  // Up
    dfs(grid, rows, cols, i, j+1);  // Right
    dfs(grid, rows, cols, i, j-1);  // Left
}

int numIslands(char grid[][100], int rows, int cols) {
    int count = 0;
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == '1') {
                count++;
                dfs(grid, rows, cols, i, j);
            }
        }
    }
    
    return count;
}
// Time: O(rows × cols), Space: O(rows × cols) for recursion
```

---

## 5️⃣ Time Complexity Cheat Sheet

### Data Structure Operations

| Structure   | Access   | Search   | Insert   | Delete   |
|-------------|----------|----------|----------|----------|
| Array       | O(1)     | O(n)     | O(n)     | O(n)     |
| Linked List | O(n)     | O(n)     | O(1)     | O(1)     |
| Stack       | O(n)     | O(n)     | O(1)     | O(1)     |
| Queue       | O(n)     | O(n)     | O(1)     | O(1)     |
| Hash Table  | -        | O(1)     | O(1)     | O(1)     |
| BST         | O(log n) | O(log n) | O(log n) | O(log n) |
| Heap        | -        | -        | O(log n) | O(log n) |

### Sorting Algorithms

| Algorithm  | Best       | Average    | Worst      | Space     | Stable |
|------------|------------|------------|------------|-----------|--------|
| Bubble     | O(n)       | O(n²)      | O(n²)      | O(1)      | Yes    |
| Selection  | O(n²)      | O(n²)      | O(n²)      | O(1)      | No     |
| Insertion  | O(n)       | O(n²)      | O(n²)      | O(1)      | Yes    |
| Merge      | O(n log n) | O(n log n) | O(n log n) | O(n)      | Yes    |
| Quick      | O(n log n) | O(n log n) | O(n²)      | O(log n)  | No     |
| Heap       | O(n log n) | O(n log n) | O(n log n) | O(1)      | No     |

---

## 6️⃣ Interview Success Strategies

### Before the Interview

- Review core data structures and algorithms
- Practice coding on whiteboard/paper
- Prepare questions to ask the interviewer
- Get good sleep and arrive early

### During the Interview

1. **Listen carefully** to the problem
2. **Ask clarifying questions** about constraints
3. **Think out loud** - explain your approach
4. **Start with brute force** if unsure
5. **Optimize iteratively** - don't aim for perfect first try
6. **Test your code** with examples
7. **Handle edge cases** explicitly

### Common Mistakes to Avoid

- Jumping to code without planning
- Not asking about constraints
- Silent coding without explanation
- Ignoring edge cases
- Not testing the solution
- Getting stuck on one approach

---

## 🧪 Final Mock Test

### Problem Set (60 minutes)

**Easy (15 min):**

1. Reverse a linked list
2. Valid parentheses checker
3. Two sum problem

**Medium (25 min):**
4. Merge intervals
5. Binary tree level order traversal
6. Longest substring without repeating characters

**Hard (20 min):**
7. Serialize and deserialize binary tree
8. Trapping rain water

---

## 🎯 Final Interview Tips

✓ **Practice coding without IDE** - Use paper or whiteboard
✓ **Explain everything** - Communication is key
✓ **Multiple solutions** - Show you can optimize
✓ **Edge cases matter** - Empty input, single element, large input
✓ **Complexity analysis** - Always state time and space
✓ **Stay calm** - It's okay to ask for hints
✓ **Think aloud** - Interviewers want to see your thought process

### What Interviewers Look For

1. Problem-solving ability
2. Code quality and style
3. Communication skills
4. Handling of edge cases
5. Complexity analysis understanding
6. Ability to optimize
7. Debugging skills

---

## 📚 Key Takeaways

### You've Mastered

✓ **Foundations:** Arrays, strings, linked lists, stacks, queues
✓ **Trees:** Binary trees, BST, heaps, tries
✓ **Graphs:** Traversals, shortest paths, MST
✓ **Algorithms:** Searching, sorting, recursion, DP, greedy, backtracking
✓ **Hashing:** Hash tables, collision resolution
✓ **Patterns:** Two pointers, sliding window, fast-slow pointers

### Remember

- **Practice consistently** - Do at least one problem daily
- **Learn from mistakes** - Review failed attempts
- **Time yourself** - Simulate real interview pressure
- **Focus on understanding** - Not just memorizing solutions
- **Stay confident** - You've completed 30 days of intensive training!

---

## 🎉 Congratulations

You've completed the **30-Day DSA Mastery** program!

You're now equipped with:

- Strong foundation in data structures
- Comprehensive algorithm knowledge
- Problem-solving frameworks
- Interview-ready skills
- Confidence to tackle technical interviews

### Next Steps

1. Keep practicing on LeetCode, HackerRank, CodeForces
2. Participate in coding competitions
3. Review this material regularly
4. Build projects using these concepts
5. Help others learn - teaching reinforces learning

### Good luck with your interviews! You're ready! 🚀

---

## 📝 Additional Resources

- All code examples in respective `examples/` directories
- Practice problems in `exercises/` folders
- Complete solutions in `solutions/` directories
- Online Platforms: LeetCode, HackerRank, CodeForces, GeeksforGeeks
- Books: "Cracking the Coding Interview", "Elements of Programming Interviews"

---

### 🏆 30-Day DSA Mastery Complete! 🏆
