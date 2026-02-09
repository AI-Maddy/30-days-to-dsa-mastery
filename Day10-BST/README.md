# Day 10 — Binary Search Trees (BST)

## 🎯 Mastery Goals
- Understand BST property and its significance
- Master insert, search, delete operations
- Learn tree traversals specific to BST
- Solve BST-based interview problems
- Recognize when BST is the optimal data structure

---

## 1️⃣ What is a Binary Search Tree?

A **BST** is a binary tree with the **ordering property**:
- **Left subtree** contains only nodes with keys **less than** the node's key
- **Right subtree** contains only nodes with keys **greater than** the node's key
- Both left and right subtrees must also be BSTs

```text
        8
       / \
      3   10
     / \    \
    1   6    14
       / \   /
      4   7 13

BST Property satisfied at every node!
3 < 8 < 10, 1 < 3 < 6, etc.
```

### Why BST?
- **O(log n)** average search, insert, delete (if balanced)
- **Inorder traversal gives sorted order**
- Efficient range queries
- Better than array for dynamic data

---

## 2️⃣ BST Operations

### Search — Average O(log n), Worst O(n)
```c
struct Node* search(struct Node* root, int key) {
    // Base cases: root is null or key is at root
    if (root == NULL || root->data == key)
        return root;
    
    // Key is greater than root's key
    if (root->data < key)
        return search(root->right, key);
    
    // Key is smaller than root's key
    return search(root->left, key);
}
```

### Insert — Average O(log n), Worst O(n)
```c
struct Node* insert(struct Node* root, int key) {
    // If tree is empty, return new node
    if (root == NULL)
        return createNode(key);
    
    // Otherwise, recur down the tree
    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);
    
    // Return unchanged node pointer
    return root;
}
```

### Delete — Average O(log n), Worst O(n)
```c
struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL) return root;
    
    // Recur down the tree
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        
        // Node with two children: get inorder successor
        struct Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}
```

---

## 3️⃣ BST Traversals

### Inorder (Left, Root, Right)
**Special property: Gives sorted order!**
```c
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
// Output for tree above: 1 3 4 6 7 8 10 13 14 (sorted!)
```

### Finding Min and Max
```c
int findMin(struct Node* root) {
    if (root == NULL) return -1;
    while (root->left != NULL)
        root = root->left;
    return root->data;
}

int findMax(struct Node* root) {
    if (root == NULL) return -1;
    while (root->right != NULL)
        root = root->right;
    return root->data;
}
```

---

## 4️⃣ Common BST Problems

### Problem 1: Validate BST
```c
bool isBSTUtil(struct Node* root, int min, int max) {
    if (root == NULL) return true;
    
    // Check BST property
    if (root->data < min || root->data > max)
        return false;
    
    // Recur for left and right subtrees
    return isBSTUtil(root->left, min, root->data - 1) &&
           isBSTUtil(root->right, root->data + 1, max);
}

bool isBST(struct Node* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}
```

### Problem 2: Lowest Common Ancestor in BST
```c
struct Node* LCA(struct Node* root, int n1, int n2) {
    if (root == NULL) return NULL;
    
    // If both n1 and n2 are smaller, LCA is in left
    if (root->data > n1 && root->data > n2)
        return LCA(root->left, n1, n2);
    
    // If both n1 and n2 are greater, LCA is in right
    if (root->data < n1 && root->data < n2)
        return LCA(root->right, n1, n2);
    
    // We have found the split point (LCA)
    return root;
}
// Time: O(h), more efficient than regular binary tree!
```

### Problem 3: Kth Smallest Element
```c
void kthSmallestUtil(struct Node* root, int k, int* count, int* result) {
    if (root == NULL || *count >= k) return;
    
    // Inorder traversal
    kthSmallestUtil(root->left, k, count, result);
    
    (*count)++;
    if (*count == k) {
        *result = root->data;
        return;
    }
    
    kthSmallestUtil(root->right, k, count, result);
}

int kthSmallest(struct Node* root, int k) {
    int count = 0, result = -1;
    kthSmallestUtil(root, k, &count, &result);
    return result;
}
```

### Problem 4: Convert Sorted Array to BST
```c
struct Node* sortedArrayToBST(int arr[], int start, int end) {
    if (start > end) return NULL;
    
    // Middle element as root (for balance)
    int mid = start + (end - start) / 2;
    struct Node* root = createNode(arr[mid]);
    
    // Recursively construct left and right subtrees
    root->left = sortedArrayToBST(arr, start, mid - 1);
    root->right = sortedArrayToBST(arr, mid + 1, end);
    
    return root;
}
// Time: O(n), creates a balanced BST!
```

---

## 5️⃣ BST vs Hash Table

| Operation | BST (balanced) | Hash Table |
|-----------|----------------|------------|
| **Search** | O(log n) | O(1) average |
| **Insert** | O(log n) | O(1) average |
| **Delete** | O(log n) | O(1) average |
| **Sorted traversal** | O(n) | O(n log n) |
| **Range queries** | O(log n + k) | O(n) |
| **Min/Max** | O(log n) | O(n) |

**Use BST when you need:**
- Sorted order
- Range queries
- Predecessor/successor operations

---

## 🧪 Practice Exercises

### Exercise 1: Inorder Successor
Find the next node in inorder traversal

**Hint:** If node has right child, successor is leftmost node in right subtree

### Exercise 2: Check if two BSTs are identical
Compare structure and values

### Exercise 3: Convert BST to Greater Tree
Each node's value = sum of all greater nodes

---

## 🎯 Interview Tips

✓ **Always verify:** Is it a BST? Check the property!  
✓ **Remember:** Inorder gives sorted order  
✓ **Optimize:** Use BST property to prune search space  
✓ **Balance matters:** O(log n) only if balanced  

---

## 📚 Key Takeaways

- BST: Left < Root < Right property at every node
- Operations: O(log n) average if balanced, O(n) worst
- Inorder traversal gives sorted order
- Better than hash table for ordered operations
- Foundation for self-balancing trees (AVL, Red-Black)

---

**Next:** Day 11 - Heaps (complete binary tree with heap property)
