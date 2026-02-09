# Day 09 — Binary Trees

## 🎯 Mastery Goals
- Understand tree terminology and properties
- Master tree traversals (inorder, preorder, postorder, level-order)
- Calculate tree height, size, and other properties
- Solve tree-based interview problems
- Recognize tree patterns (subtree, path, diameter)

---

## 1️⃣ What is a Binary Tree?

A **binary tree** is a hierarchical structure where each node has at most 2 children.

```text
        1          ← Root
       / \
      2   3        ← Level 1
     / \   \
    4   5   6      ← Level 2 (Leaves: 4, 5, 6)
```

### Node Structure
```c
typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;
```

---

## 2️⃣ Tree Terminology

| Term | Definition |
|------|------------|
| **Root** | Top node (no parent) |
| **Parent** | Node with children |
| **Child** | Node with parent |
| **Leaf** | Node with no children |
| **Height** | Longest path from node to leaf |
| **Depth** | Distance from root to node |
| **Level** | All nodes at same depth |

**Tree Height:** Edges in longest path from root to leaf
- Empty tree: -1 or 0 (convention varies)
- Single node: 0
- Tree above: 2

---

## 3️⃣ Types of Binary Trees

### Full Binary Tree
Every node has 0 or 2 children (no node has 1 child)

### Complete Binary Tree
All levels filled except last (filled left to right)
```text
        1
       / \
      2   3     ← Complete
     / \
    4   5
```

### Perfect Binary Tree
All internal nodes have 2 children, all leaves at same level
- Nodes: 2^(h+1) - 1

### Balanced Binary Tree
Height difference of left and right subtrees ≤ 1 for every node

---

## 4️⃣ Tree Traversals

### Depth-First Traversals

**Inorder (Left, Root, Right)**
```c
void inorder(TreeNode* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
// Output for tree above: 4 2 5 1 3 6
// For BST: gives sorted order!
```

**Preorder (Root, Left, Right)**
```c
void preorder(TreeNode* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}
// Output: 1 2 4 5 3 6
// Use: Copy tree, expression tree prefix
```

**Postorder (Left, Right, Root)**
```c
void postorder(TreeNode* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root ->data);
}
// Output: 4 5 2 6 3 1
// Use: Delete tree, expression evaluation
```

### Breadth-First Traversal

**Level Order (BFS)**
```c
void levelOrder(TreeNode* root) {
    if (!root) return;
    
    Queue q;
    initQueue(&q);
    enqueue(&q, root);
    
    while (!isEmpty(&q)) {
        TreeNode* node = dequeue(&q);
        printf("%d ", node->data);
        
        if (node->left) enqueue(&q, node->left);
        if (node->right) enqueue(&q, node->right);
    }
}
// Output: 1 2 3 4 5 6
```

---

## 5️⃣ Common Tree Problems

### Problem 1: Tree Height/Depth
```c
int height(TreeNode* root) {
    if (root == NULL) return -1;  // or 0, depends on convention
    
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}
// Time: O(n), Space: O(h) where h = height
```

### Problem 2: Count Nodes
```c
int countNodes(TreeNode* root) {
    if (root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}
```

### Problem 3: Check if Balanced
```c
int checkHeight(TreeNode* root) {
    if (root == NULL) return 0;
    
    int leftHeight = checkHeight(root->left);
    if (leftHeight == -1) return -1;  // Already unbalanced
    
    int rightHeight = checkHeight(root->right);
    if (rightHeight == -1) return -1;
    
    // Check balance condition
    if (abs(leftHeight - rightHeight) > 1)
        return -1;  // Unbalanced
    
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

bool isBalanced(TreeNode* root) {
    return checkHeight(root) != -1;
}
```

### Problem 4: Diameter (Longest Path)
```c
int diameterHelper(TreeNode* root, int* diameter) {
    if (root == NULL) return 0;
    
    int left = diameterHelper(root->left, diameter);
    int right = diameterHelper(root->right, diameter);
    
    // Update diameter if path through root is longer
    *diameter = (*diameter > left + right) ? *diameter : left + right;
    
    return 1 + (left > right ? left : right);
}

int diameter(TreeNode* root) {
    int diam = 0;
    diameterHelper(root, &diam);
    return diam;
}
```

### Problem 5: Lowest Common Ancestor (LCA)
```c
TreeNode* LCA(TreeNode* root, int n1, int n2) {
    if (root == NULL) return NULL;
    
    // If either n1 or n2 matches root
    if (root->data == n1 || root->data == n2)
        return root;
    
    // Recur for left and right subtrees
    TreeNode* left = LCA(root->left, n1, n2);
    TreeNode* right = LCA(root->right, n1, n2);
    
    // If both return non-NULL, root is LCA
    if (left && right) return root;
    
    // Otherwise return non-NULL child
    return left ? left : right;
}
```

---

## 6️⃣ Tree Construction

### From Inorder + Preorder
```c
// Inorder: [4, 2, 5, 1, 3, 6]
// Preorder: [1, 2, 4, 5, 3, 6]
// First element of preorder is root
// Find it in inorder to split left/right subtrees
```

### From Inorder + Postorder
```c
// Last element of postorder is root
```

**Note:** Cannot uniquely construct tree from preorder + postorder alone!

---

## 🧪 Practice Exercises

### Exercise 1: Mirror Tree
Convert tree to its mirror image (swap left/right for all nodes)

### Exercise 2: Path Sum
Check if path from root to leaf sums to target

### Exercise 3: Serialize and Deserialize
Convert tree to string and back

---

## 🎯 Interview Tips

✓ **Always check:** NULL pointer before accessing  
✓ **Common pattern:** Recursion on left and right subtrees  
✓ **Traversal choice:** Inorder for BST, level-order for level problems  
✓ **Space complexity:** O(h) for recursion stack  

---

## 📚 Key Takeaways

- Binary tree: at most 2 children per node
- Master 4 traversals: inorder, preorder, postorder, level-order
- Recursion is natural for tree problems
- Height, diameter, LCA are common interview patterns

---

**Next:** Day 10 - Binary Search Trees (BST with ordering property)
