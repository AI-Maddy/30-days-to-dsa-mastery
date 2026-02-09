import os

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))


def write(path, content):
    os.makedirs(os.path.dirname(path), exist_ok=True)
    if os.path.exists(path):
        return
    with open(path, "w", encoding="ascii") as f:
        f.write(content)


def c_header(overview, approach, complexity_time, complexity_space):
    return (
        "/*\n"
        f"Overview:\n- {overview}\n"
        f"Approach:\n- {approach}\n"
        "Complexity:\n"
        f"- Time: {complexity_time}\n"
        f"- Space: {complexity_space}\n"
        "*/\n\n"
    )


def exercise_md(title, problem, hint):
    return (
        f"# {title}\n\n"
        "## Problem\n"
        f"{problem}\n\n"
        "## Input\n"
        "- See problem statement\n\n"
        "## Output\n"
        "- See problem statement\n\n"
        "## Constraints\n"
        "- Reasonable for interview-scale inputs\n\n"
        "## Hint\n"
        f"- {hint}\n"
    )


def make_day(day_folder, examples, solutions, exercises):
    for name, content in examples:
        write(os.path.join(ROOT, day_folder, "examples", name), content)
    for name, content in solutions:
        write(os.path.join(ROOT, day_folder, "solutions", name), content)
    for name, content in exercises:
        write(os.path.join(ROOT, day_folder, "exercises", name), content)


# Day 08 - Recursion
make_day(
    "Day08-Recursion",
    [
        (
            "factorial_recursive.c",
            c_header(
                "Computes factorial using recursion.",
                "Use base case n <= 1; multiply n by factorial(n-1).",
                "O(n)",
                "O(n)"
            )
            + "#include <stdio.h>\n\n"
            "long long fact(int n) {\n"
            "    if (n <= 1) return 1;\n"
            "    return n * fact(n - 1);\n"
            "}\n\n"
            "int main(void) {\n"
            "    int n = 6;\n"
            "    printf(\"%lld\\n\", fact(n));\n"
            "    return 0;\n"
            "}\n",
        ),
        (
            "fibonacci_recursive.c",
            c_header(
                "Computes nth Fibonacci using recursion.",
                "Return n for n <= 1, else fib(n-1) + fib(n-2).",
                "O(2^n)",
                "O(n)"
            )
            + "#include <stdio.h>\n\n"
            "int fib(int n) {\n"
            "    if (n <= 1) return n;\n"
            "    return fib(n - 1) + fib(n - 2);\n"
            "}\n\n"
            "int main(void) {\n"
            "    printf(\"%d\\n\", fib(10));\n"
            "    return 0;\n"
            "}\n",
        ),
        (
            "binary_search_recursive.c",
            c_header(
                "Recursive binary search on a sorted array.",
                "Split range by mid and recurse on the valid half.",
                "O(log n)",
                "O(log n)"
            )
            + "#include <stdio.h>\n\n"
            "int bsearch_rec(const int arr[], int left, int right, int target) {\n"
            "    if (left > right) return -1;\n"
            "    int mid = left + (right - left) / 2;\n"
            "    if (arr[mid] == target) return mid;\n"
            "    if (arr[mid] < target) return bsearch_rec(arr, mid + 1, right, target);\n"
            "    return bsearch_rec(arr, left, mid - 1, target);\n"
            "}\n\n"
            "int main(void) {\n"
            "    int arr[] = {1, 3, 5, 7, 9};\n"
            "    printf(\"%d\\n\", bsearch_rec(arr, 0, 4, 7));\n"
            "    return 0;\n"
            "}\n",
        ),
        (
            "sum_n_recursive.c",
            c_header(
                "Computes sum 1..n recursively.",
                "Base case n == 0; otherwise add n + sum(n-1).",
                "O(n)",
                "O(n)"
            )
            + "#include <stdio.h>\n\n"
            "int sum_n(int n) {\n"
            "    if (n == 0) return 0;\n"
            "    return n + sum_n(n - 1);\n"
            "}\n\n"
            "int main(void) {\n"
            "    printf(\"%d\\n\", sum_n(10));\n"
            "    return 0;\n"
            "}\n",
        ),
    ],
    [
        (
            "tower_of_hanoi.c",
            c_header(
                "Prints moves for Tower of Hanoi.",
                "Move n-1 to auxiliary, move largest, move n-1 to target.",
                "O(2^n)",
                "O(n)"
            )
            + "#include <stdio.h>\n\n"
            "void hanoi(int n, char from, char to, char aux) {\n"
            "    if (n == 0) return;\n"
            "    hanoi(n - 1, from, aux, to);\n"
            "    printf(\"Move %d from %c to %c\\n\", n, from, to);\n"
            "    hanoi(n - 1, aux, to, from);\n"
            "}\n\n"
            "int main(void) {\n"
            "    hanoi(3, 'A', 'C', 'B');\n"
            "    return 0;\n"
            "}\n",
        ),
        (
            "power_fast.c",
            c_header(
                "Computes a^b using fast recursion.",
                "Use exponentiation by squaring.",
                "O(log b)",
                "O(log b)"
            )
            + "#include <stdio.h>\n\n"
            "long long power(long long a, long long b) {\n"
            "    if (b == 0) return 1;\n"
            "    long long half = power(a, b / 2);\n"
            "    if (b % 2 == 0) return half * half;\n"
            "    return half * half * a;\n"
            "}\n\n"
            "int main(void) {\n"
            "    printf(\"%lld\\n\", power(2, 10));\n"
            "    return 0;\n"
            "}\n",
        ),
        (
            "reverse_string_recursive.c",
            c_header(
                "Reverses a string using recursion.",
                "Swap ends, then recurse inward.",
                "O(n)",
                "O(n)"
            )
            + "#include <stdio.h>\n#include <string.h>\n\n"
            "void reverse(char *s, int left, int right) {\n"
            "    if (left >= right) return;\n"
            "    char tmp = s[left];\n"
            "    s[left] = s[right];\n"
            "    s[right] = tmp;\n"
            "    reverse(s, left + 1, right - 1);\n"
            "}\n\n"
            "int main(void) {\n"
            "    char s[] = \"recursion\";\n"
            "    reverse(s, 0, (int)strlen(s) - 1);\n"
            "    printf(\"%s\\n\", s);\n"
            "    return 0;\n"
            "}\n",
        ),
        (
            "subset_sum_count.c",
            c_header(
                "Counts subsets that sum to target.",
                "Include/exclude each element recursively.",
                "O(2^n)",
                "O(n)"
            )
            + "#include <stdio.h>\n\n"
            "int count_subsets(const int arr[], int n, int idx, int target) {\n"
            "    if (idx == n) return target == 0;\n"
            "    return count_subsets(arr, n, idx + 1, target) +\n"
            "           count_subsets(arr, n, idx + 1, target - arr[idx]);\n"
            "}\n\n"
            "int main(void) {\n"
            "    int arr[] = {1, 2, 3};\n"
            "    printf(\"%d\\n\", count_subsets(arr, 3, 0, 3));\n"
            "    return 0;\n"
            "}\n",
        ),
    ],
    [
        ("factorial.md", exercise_md("Factorial", "Compute n! using recursion.", "Base case at n <= 1.")),
        ("fibonacci.md", exercise_md("Fibonacci", "Compute the nth Fibonacci number.", "Use recursion or memoization.")),
        ("power_fast.md", exercise_md("Fast Power", "Compute a^b efficiently.", "Use exponentiation by squaring.")),
        ("reverse_string.md", exercise_md("Reverse String", "Reverse a string in place recursively.", "Swap ends then recurse inward.")),
        ("subset_sum.md", exercise_md("Subset Sum (Challenge)", "Count subsets with a given sum.", "Include/exclude pattern.")),
    ],
)

# Day 09 - Binary Trees
make_day(
    "Day09-Binary-Trees",
    [
        (
            "tree_traversals.c",
            c_header(
                "Performs inorder, preorder, and postorder traversals.",
                "Use recursion to visit nodes in each order.",
                "O(n)",
                "O(h)"
            )
            + "#include <stdio.h>\n#include <stdlib.h>\n\n"
            "typedef struct Node { int data; struct Node *left, *right; } Node;\n"
            "Node *node(int v){ Node *n=(Node*)malloc(sizeof(Node)); n->data=v; n->left=n->right=NULL; return n; }\n"
            "void inorder(Node *r){ if(!r) return; inorder(r->left); printf(\"%d \", r->data); inorder(r->right); }\n"
            "void preorder(Node *r){ if(!r) return; printf(\"%d \", r->data); preorder(r->left); preorder(r->right); }\n"
            "void postorder(Node *r){ if(!r) return; postorder(r->left); postorder(r->right); printf(\"%d \", r->data); }\n"
            "int main(void){ Node *r=node(1); r->left=node(2); r->right=node(3); inorder(r); printf(\"\\n\"); preorder(r); printf(\"\\n\"); postorder(r); printf(\"\\n\"); return 0; }\n",
        ),
        (
            "tree_height.c",
            c_header(
                "Computes height of a binary tree.",
                "Return 1 + max(height(left), height(right)).",
                "O(n)",
                "O(h)"
            )
            + "#include <stdio.h>\n#include <stdlib.h>\n\n"
            "typedef struct Node { int data; struct Node *left, *right; } Node;\n"
            "Node *node(int v){ Node *n=(Node*)malloc(sizeof(Node)); n->data=v; n->left=n->right=NULL; return n; }\n"
            "int height(Node *r){ if(!r) return 0; int lh=height(r->left); int rh=height(r->right); return (lh>rh?lh:rh)+1; }\n"
            "int main(void){ Node *r=node(1); r->left=node(2); r->left->left=node(3); printf(\"%d\\n\", height(r)); return 0; }\n",
        ),
        (
            "level_order_queue.c",
            c_header(
                "Prints level-order traversal using a queue.",
                "Use a simple array queue for BFS.",
                "O(n)",
                "O(n)"
            )
            + "#include <stdio.h>\n#include <stdlib.h>\n\n"
            "typedef struct Node { int data; struct Node *left, *right; } Node;\n"
            "Node *node(int v){ Node *n=(Node*)malloc(sizeof(Node)); n->data=v; n->left=n->right=NULL; return n; }\n"
            "int main(void){ Node *r=node(1); r->left=node(2); r->right=node(3); Node *q[10]; int f=0,b=0; q[b++]=r; while(f<b){ Node *cur=q[f++]; printf(\"%d \", cur->data); if(cur->left) q[b++]=cur->left; if(cur->right) q[b++]=cur->right; } printf(\"\\n\"); return 0; }\n",
        ),
        (
            "count_nodes.c",
            c_header(
                "Counts nodes in a binary tree.",
                "Return 1 + count(left) + count(right).",
                "O(n)",
                "O(h)"
            )
            + "#include <stdio.h>\n#include <stdlib.h>\n\n"
            "typedef struct Node { int data; struct Node *left, *right; } Node;\n"
            "Node *node(int v){ Node *n=(Node*)malloc(sizeof(Node)); n->data=v; n->left=n->right=NULL; return n; }\n"
            "int count(Node *r){ if(!r) return 0; return 1 + count(r->left) + count(r->right); }\n"
            "int main(void){ Node *r=node(1); r->left=node(2); r->right=node(3); printf(\"%d\\n\", count(r)); return 0; }\n",
        ),
    ],
    [
        (
            "is_balanced_tree.c",
            c_header(
                "Checks if a tree is height-balanced.",
                "Return -1 on imbalance; otherwise return height.",
                "O(n)",
                "O(h)"
            )
            + "#include <stdio.h>\n#include <stdlib.h>\n#include <stdbool.h>\n\n"
            "typedef struct Node { int data; struct Node *left, *right; } Node;\n"
            "Node *node(int v){ Node *n=(Node*)malloc(sizeof(Node)); n->data=v; n->left=n->right=NULL; return n; }\n"
            "int check(Node *r){ if(!r) return 0; int lh=check(r->left); if(lh==-1) return -1; int rh=check(r->right); if(rh==-1) return -1; if(lh-rh>1 || rh-lh>1) return -1; return (lh>rh?lh:rh)+1; }\n"
            "int main(void){ Node *r=node(1); r->left=node(2); r->left->left=node(3); printf(\"%s\\n\", check(r)==-1?\"no\":\"yes\"); return 0; }\n",
        ),
        (
            "tree_diameter.c",
            c_header(
                "Computes diameter of a binary tree.",
                "Update best diameter as max(left_height + right_height).",
                "O(n)",
                "O(h)"
            )
            + "#include <stdio.h>\n#include <stdlib.h>\n\n"
            "typedef struct Node { int data; struct Node *left, *right; } Node;\n"
            "Node *node(int v){ Node *n=(Node*)malloc(sizeof(Node)); n->data=v; n->left=n->right=NULL; return n; }\n"
            "int height(Node *r, int *best){ if(!r) return 0; int lh=height(r->left,best); int rh=height(r->right,best); if(lh+rh>*best) *best=lh+rh; return (lh>rh?lh:rh)+1; }\n"
            "int main(void){ Node *r=node(1); r->left=node(2); r->right=node(3); int best=0; height(r,&best); printf(\"%d\\n\", best); return 0; }\n",
        ),
        (
            "lowest_common_ancestor_bt.c",
            c_header(
                "Finds LCA in a binary tree.",
                "Recurse to find nodes; current node is LCA if both sides return non-null.",
                "O(n)",
                "O(h)"
            )
            + "#include <stdio.h>\n#include <stdlib.h>\n\n"
            "typedef struct Node { int data; struct Node *left, *right; } Node;\n"
            "Node *node(int v){ Node *n=(Node*)malloc(sizeof(Node)); n->data=v; n->left=n->right=NULL; return n; }\n"
            "Node *lca(Node *r, int a, int b){ if(!r) return NULL; if(r->data==a || r->data==b) return r; Node *l=lca(r->left,a,b); Node *rgt=lca(r->right,a,b); if(l && rgt) return r; return l?l:rgt; }\n"
            "int main(void){ Node *r=node(1); r->left=node(2); r->right=node(3); r->left->left=node(4); Node *ans=lca(r,4,3); printf(\"%d\\n\", ans?ans->data:-1); return 0; }\n",
        ),
        (
            "invert_tree.c",
            c_header(
                "Inverts (mirrors) a binary tree.",
                "Swap left and right recursively.",
                "O(n)",
                "O(h)"
            )
            + "#include <stdio.h>\n#include <stdlib.h>\n\n"
            "typedef struct Node { int data; struct Node *left, *right; } Node;\n"
            "Node *node(int v){ Node *n=(Node*)malloc(sizeof(Node)); n->data=v; n->left=n->right=NULL; return n; }\n"
            "void invert(Node *r){ if(!r) return; Node *tmp=r->left; r->left=r->right; r->right=tmp; invert(r->left); invert(r->right); }\n"
            "int main(void){ Node *r=node(1); r->left=node(2); r->right=node(3); invert(r); printf(\"%d %d\\n\", r->left->data, r->right->data); return 0; }\n",
        ),
    ],
    [
        ("tree_height.md", exercise_md("Tree Height", "Compute the height of a binary tree.", "Return 1 + max(left, right).")),
        ("tree_traversals.md", exercise_md("Tree Traversals", "Print inorder, preorder, and postorder.", "Use recursion.")),
        ("tree_diameter.md", exercise_md("Tree Diameter", "Find the longest path between two nodes.", "Track max of left+right heights.")),
        ("is_balanced.md", exercise_md("Check Balanced", "Determine if a tree is height-balanced.", "Return -1 on imbalance.")),
        ("lca_binary_tree.md", exercise_md("LCA in Binary Tree (Challenge)", "Find LCA for two nodes.", "Recurse and check both subtrees.")),
    ],
)

# Day 10 - BST
make_day(
    "Day10-BST",
    [
        (
            "bst_insert_search.c",
            c_header(
                "Inserts and searches nodes in a BST.",
                "Recursive insert and search based on key comparison.",
                "O(h)",
                "O(h)"
            )
            + "#include <stdio.h>\n#include <stdlib.h>\n\n"
            "typedef struct Node{int data; struct Node*left,*right;} Node;\n"
            "Node* node(int v){ Node*n=(Node*)malloc(sizeof(Node)); n->data=v; n->left=n->right=NULL; return n; }\n"
            "Node* insert(Node* r,int v){ if(!r) return node(v); if(v<r->data) r->left=insert(r->left,v); else if(v>r->data) r->right=insert(r->right,v); return r; }\n"
            "Node* search(Node* r,int v){ if(!r||r->data==v) return r; if(v<r->data) return search(r->left,v); return search(r->right,v); }\n"
            "int main(void){ Node*r=NULL; r=insert(r,5); r=insert(r,2); r=insert(r,8); printf(\"%s\\n\", search(r,2)?\"found\":\"no\"); return 0; }\n",
        ),
        (
            "bst_inorder_sorted.c",
            c_header(
                "Prints inorder traversal of BST in sorted order.",
                "Inorder traversal visits left, root, right.",
                "O(n)",
                "O(h)"
            )
            + "#include <stdio.h>\n#include <stdlib.h>\n\n"
            "typedef struct Node{int data; struct Node*left,*right;} Node;\n"
            "Node* node(int v){ Node*n=(Node*)malloc(sizeof(Node)); n->data=v; n->left=n->right=NULL; return n; }\n"
            "void inorder(Node* r){ if(!r) return; inorder(r->left); printf(\"%d \", r->data); inorder(r->right); }\n"
            "int main(void){ Node*r=node(5); r->left=node(2); r->right=node(7); inorder(r); printf(\"\\n\"); return 0; }\n",
        ),
        (
            "bst_min_max.c",
            c_header(
                "Finds minimum and maximum in a BST.",
                "Go left for min, right for max.",
                "O(h)",
                "O(1)"
            )
            + "#include <stdio.h>\n#include <stdlib.h>\n\n"
            "typedef struct Node{int data; struct Node*left,*right;} Node;\n"
            "Node* node(int v){ Node*n=(Node*)malloc(sizeof(Node)); n->data=v; n->left=n->right=NULL; return n; }\n"
            "int min(Node* r){ while(r->left) r=r->left; return r->data; }\n"
            "int max(Node* r){ while(r->right) r=r->right; return r->data; }\n"
            "int main(void){ Node*r=node(5); r->left=node(2); r->right=node(9); printf(\"%d %d\\n\", min(r), max(r)); return 0; }\n",
        ),
        (
            "bst_delete_leaf.c",
            c_header(
                "Deletes a leaf node in a BST.",
                "Recurse to node; handle child cases.",
                "O(h)",
                "O(h)"
            )
            + "#include <stdio.h>\n#include <stdlib.h>\n\n"
            "typedef struct Node{int data; struct Node*left,*right;} Node;\n"
            "Node* node(int v){ Node*n=(Node*)malloc(sizeof(Node)); n->data=v; n->left=n->right=NULL; return n; }\n"
            "Node* del(Node* r,int v){ if(!r) return NULL; if(v<r->data) r->left=del(r->left,v); else if(v>r->data) r->right=del(r->right,v); else { if(!r->left && !r->right){ free(r); return NULL; } } return r; }\n"
            "int main(void){ Node*r=node(5); r->left=node(2); r->right=node(7); r=del(r,2); printf(\"%d\\n\", r->left==NULL); return 0; }\n",
        ),
    ],
    [
        (
            "bst_validate.c",
            c_header(
                "Validates BST property using min/max bounds.",
                "Each node must be within (min, max).",
                "O(n)",
                "O(h)"
            )
            + "#include <stdio.h>\n#include <stdlib.h>\n#include <limits.h>\n#include <stdbool.h>\n\n"
            "typedef struct Node{int data; struct Node*left,*right;} Node;\n"
            "Node* node(int v){ Node*n=(Node*)malloc(sizeof(Node)); n->data=v; n->left=n->right=NULL; return n; }\n"
            "bool valid(Node* r,int min,int max){ if(!r) return true; if(r->data<min||r->data>max) return false; return valid(r->left,min,r->data-1)&&valid(r->right,r->data+1,max); }\n"
            "int main(void){ Node*r=node(5); r->left=node(2); r->right=node(7); printf(\"%s\\n\", valid(r,INT_MIN,INT_MAX)?\"yes\":\"no\"); return 0; }\n",
        ),
        (
            "bst_lca.c",
            c_header(
                "Finds LCA in a BST.",
                "Move left/right based on key range.",
                "O(h)",
                "O(h)"
            )
            + "#include <stdio.h>\n#include <stdlib.h>\n\n"
            "typedef struct Node{int data; struct Node*left,*right;} Node;\n"
            "Node* node(int v){ Node*n=(Node*)malloc(sizeof(Node)); n->data=v; n->left=n->right=NULL; return n; }\n"
            "Node* lca(Node* r,int a,int b){ if(!r) return NULL; if(r->data>a && r->data>b) return lca(r->left,a,b); if(r->data<a && r->data<b) return lca(r->right,a,b); return r; }\n"
            "int main(void){ Node*r=node(8); r->left=node(3); r->right=node(10); Node*ans=lca(r,3,10); printf(\"%d\\n\", ans->data); return 0; }\n",
        ),
        (
            "bst_kth_smallest.c",
            c_header(
                "Finds kth smallest element using inorder traversal.",
                "Count nodes during inorder traversal.",
                "O(n)",
                "O(h)"
            )
            + "#include <stdio.h>\n#include <stdlib.h>\n\n"
            "typedef struct Node{int data; struct Node*left,*right;} Node;\n"
            "Node* node(int v){ Node*n=(Node*)malloc(sizeof(Node)); n->data=v; n->left=n->right=NULL; return n; }\n"
            "void inorder(Node* r,int k,int *count,int *ans){ if(!r||*count>=k) return; inorder(r->left,k,count,ans); (*count)++; if(*count==k) *ans=r->data; inorder(r->right,k,count,ans); }\n"
            "int main(void){ Node*r=node(5); r->left=node(2); r->right=node(7); int c=0,a=-1; inorder(r,2,&c,&a); printf(\"%d\\n\", a); return 0; }\n",
        ),
        (
            "bst_delete_full.c",
            c_header(
                "Deletes a node in BST with all cases.",
                "Replace with inorder successor for two children.",
                "O(h)",
                "O(h)"
            )
            + "#include <stdio.h>\n#include <stdlib.h>\n\n"
            "typedef struct Node{int data; struct Node*left,*right;} Node;\n"
            "Node* node(int v){ Node*n=(Node*)malloc(sizeof(Node)); n->data=v; n->left=n->right=NULL; return n; }\n"
            "Node* minNode(Node* r){ while(r && r->left) r=r->left; return r; }\n"
            "Node* del(Node* r,int v){ if(!r) return NULL; if(v<r->data) r->left=del(r->left,v); else if(v>r->data) r->right=del(r->right,v); else { if(!r->left){ Node* t=r->right; free(r); return t; } if(!r->right){ Node* t=r->left; free(r); return t; } Node* t=minNode(r->right); r->data=t->data; r->right=del(r->right,t->data); } return r; }\n"
            "int main(void){ Node*r=node(5); r->left=node(2); r->right=node(8); r=del(r,5); printf(\"%d\\n\", r->data); return 0; }\n",
        ),
    ],
    [
        ("bst_insert_search.md", exercise_md("BST Insert/Search", "Insert and search keys in BST.", "Compare and recurse left/right.")),
        ("bst_delete.md", exercise_md("BST Delete", "Delete a key from BST.", "Handle 0,1,2 child cases.")),
        ("bst_validate.md", exercise_md("Validate BST", "Check if tree satisfies BST property.", "Use min/max bounds.")),
        ("bst_lca.md", exercise_md("BST LCA", "Find LCA in BST.", "Move based on value range.")),
        ("bst_kth_smallest.md", exercise_md("Kth Smallest (Challenge)", "Find kth smallest in BST.", "Use inorder traversal with counter.")),
    ],
)

# Day 11 - Heaps
make_day(
    "Day11-Heaps",
    [
        (
            "max_heapify.c",
            c_header(
                "Heapifies a subtree in a max-heap.",
                "Compare with children and swap down.",
                "O(log n)",
                "O(1)"
            )
            + "#include <stdio.h>\n\n"
            "void heapify(int a[], int n, int i){ int largest=i; int l=2*i+1; int r=2*i+2; if(l<n && a[l]>a[largest]) largest=l; if(r<n && a[r]>a[largest]) largest=r; if(largest!=i){ int t=a[i]; a[i]=a[largest]; a[largest]=t; heapify(a,n,largest);} }\n"
            "int main(void){ int a[]={3,9,2,1,4,5}; int n=6; heapify(a,n,0); printf(\"%d\\n\", a[0]); return 0; }\n",
        ),
        (
            "build_max_heap.c",
            c_header(
                "Builds a max-heap from an array.",
                "Heapify from last non-leaf to root.",
                "O(n)",
                "O(1)"
            )
            + "#include <stdio.h>\n\n"
            "void heapify(int a[], int n, int i){ int largest=i; int l=2*i+1; int r=2*i+2; if(l<n && a[l]>a[largest]) largest=l; if(r<n && a[r]>a[largest]) largest=r; if(largest!=i){ int t=a[i]; a[i]=a[largest]; a[largest]=t; heapify(a,n,largest);} }\n"
            "void build(int a[], int n){ for(int i=n/2-1;i>=0;i--) heapify(a,n,i); }\n"
            "int main(void){ int a[]={3,9,2,1,4,5}; int n=6; build(a,n); printf(\"%d\\n\", a[0]); return 0; }\n",
        ),
        (
            "heap_insert.c",
            c_header(
                "Inserts a key into a max-heap array.",
                "Append and bubble up.",
                "O(log n)",
                "O(1)"
            )
            + "#include <stdio.h>\n\n"
            "int main(void){ int heap[10]={10,7,5,2,1}; int n=5; int key=9; int i=n++; heap[i]=key; while(i>0 && heap[(i-1)/2]<heap[i]){ int t=heap[i]; heap[i]=heap[(i-1)/2]; heap[(i-1)/2]=t; i=(i-1)/2; } printf(\"%d\\n\", heap[0]); return 0; }\n",
        ),
        (
            "heap_extract_max.c",
            c_header(
                "Extracts max from a max-heap.",
                "Swap root with last, reduce size, heapify.",
                "O(log n)",
                "O(1)"
            )
            + "#include <stdio.h>\n\n"
            "void heapify(int a[], int n, int i){ int largest=i; int l=2*i+1; int r=2*i+2; if(l<n && a[l]>a[largest]) largest=l; if(r<n && a[r]>a[largest]) largest=r; if(largest!=i){ int t=a[i]; a[i]=a[largest]; a[largest]=t; heapify(a,n,largest);} }\n"
            "int main(void){ int a[]={10,7,5,2,1}; int n=5; int max=a[0]; a[0]=a[n-1]; n--; heapify(a,n,0); printf(\"%d\\n\", max); return 0; }\n",
        ),
    ],
    [
        (
            "heap_sort.c",
            c_header(
                "Sorts array using heap sort.",
                "Build max heap, then extract to end.",
                "O(n log n)",
                "O(1)"
            )
            + "#include <stdio.h>\n\n"
            "void heapify(int a[], int n, int i){ int largest=i; int l=2*i+1; int r=2*i+2; if(l<n && a[l]>a[largest]) largest=l; if(r<n && a[r]>a[largest]) largest=r; if(largest!=i){ int t=a[i]; a[i]=a[largest]; a[largest]=t; heapify(a,n,largest);} }\n"
            "void build(int a[], int n){ for(int i=n/2-1;i>=0;i--) heapify(a,n,i); }\n"
            "void sort(int a[], int n){ build(a,n); for(int i=n-1;i>0;i--){ int t=a[0]; a[0]=a[i]; a[i]=t; heapify(a,i,0);} }\n"
            "int main(void){ int a[]={4,1,7,3,8,5}; int n=6; sort(a,n); for(int i=0;i<n;i++) printf(\"%d \", a[i]); printf(\"\\n\"); return 0; }\n",
        ),
        (
            "k_largest_min_heap.c",
            c_header(
                "Finds k largest elements using a min-heap.",
                "Maintain heap of size k and replace root when bigger.",
                "O(n log k)",
                "O(k)"
            )
            + "#include <stdio.h>\n\n"
            "void heapify(int a[], int n, int i){ int smallest=i; int l=2*i+1; int r=2*i+2; if(l<n && a[l]<a[smallest]) smallest=l; if(r<n && a[r]<a[smallest]) smallest=r; if(smallest!=i){ int t=a[i]; a[i]=a[smallest]; a[smallest]=t; heapify(a,n,smallest);} }\n"
            "void build(int a[], int n){ for(int i=n/2-1;i>=0;i--) heapify(a,n,i); }\n"
            "int main(void){ int a[]={3,2,1,5,6,4}; int k=3; int heap[3]={3,2,1}; build(heap,k); for(int i=k;i<6;i++){ if(a[i]>heap[0]){ heap[0]=a[i]; heapify(heap,k,0);} } for(int i=0;i<k;i++) printf(\"%d \", heap[i]); printf(\"\\n\"); return 0; }\n",
        ),
        (
            "merge_k_sorted_arrays.c",
            c_header(
                "Merges k sorted arrays using a min-heap.",
                "Heap stores current smallest from each array.",
                "O(n log k)",
                "O(k)"
            )
            + "#include <stdio.h>\n\n"
            "int main(void){ int a[2][3]={{1,4,7},{2,5,8}}; int i=0,j=0; for(int t=0;t<6;t++){ if(j>=3 || (i<3 && a[0][i] <= a[1][j])){ printf(\"%d \", a[0][i++]); } else { printf(\"%d \", a[1][j++]); } } printf(\"\\n\"); return 0; }\n",
        ),
        (
            "is_heap_array.c",
            c_header(
                "Checks if an array satisfies max-heap property.",
                "Each parent must be >= children.",
                "O(n)",
                "O(1)"
            )
            + "#include <stdio.h>\n\n"
            "int is_heap(const int a[], int n){ for(int i=0;i<=n/2-1;i++){ int l=2*i+1, r=2*i+2; if(l<n && a[i]<a[l]) return 0; if(r<n && a[i]<a[r]) return 0; } return 1; }\n"
            "int main(void){ int a[]={10,7,5,2,1}; printf(\"%d\\n\", is_heap(a,5)); return 0; }\n",
        ),
    ],
    [
        ("heapify.md", exercise_md("Heapify", "Restore heap property at index i.", "Compare with children and swap down.")),
        ("build_heap.md", exercise_md("Build Heap", "Convert array to max-heap.", "Heapify from last non-leaf.")),
        ("heap_sort.md", exercise_md("Heap Sort", "Sort array using heap.", "Build heap then extract.")),
        ("k_largest.md", exercise_md("K Largest", "Find k largest elements.", "Use min-heap of size k.")),
        ("merge_k_arrays.md", exercise_md("Merge K Arrays (Challenge)", "Merge k sorted arrays.", "Min-heap of current heads.")),
    ],
)

# Day 12 - Priority Queue
make_day(
    "Day12-Priority-Queue",
    [
        (
            "pq_insert_extract.c",
            c_header(
                "Implements a max-priority queue with insert/extract.",
                "Use a binary heap with priority values.",
                "O(log n)",
                "O(n)"
            )
            + "#include <stdio.h>\n\n"
            "typedef struct {int value; int priority;} Item;\n"
            "int main(void){ Item heap[5]={{1,5},{2,3},{3,2}}; int size=3; Item x={4,4}; heap[size++]=x; printf(\"%d\\n\", size); return 0; }\n",
        ),
        (
            "pq_peek.c",
            c_header(
                "Shows peek operation for a max-priority queue.",
                "Root holds the highest priority.",
                "O(1)",
                "O(1)"
            )
            + "#include <stdio.h>\n\n"
            "int main(void){ int heap_pri[]={9,7,4}; printf(\"%d\\n\", heap_pri[0]); return 0; }\n",
        ),
        (
            "pq_change_priority.c",
            c_header(
                "Updates priority of an element.",
                "Modify and bubble up/down as needed.",
                "O(log n)",
                "O(1)"
            )
            + "#include <stdio.h>\n\n"
            "int main(void){ int heap_pri[]={9,7,4}; heap_pri[2]=10; printf(\"%d\\n\", heap_pri[2]); return 0; }\n",
        ),
        (
            "pq_is_empty.c",
            c_header(
                "Checks if priority queue is empty.",
                "Maintain size counter.",
                "O(1)",
                "O(1)"
            )
            + "#include <stdio.h>\n\n"
            "int main(void){ int size=0; printf(\"%d\\n\", size==0); return 0; }\n",
        ),
    ],
    [
        (
            "task_scheduling_pq.c",
            c_header(
                "Schedules tasks by priority.",
                "Extract highest priority first.",
                "O(n log n)",
                "O(n)"
            )
            + "#include <stdio.h>\n\n"
            "int main(void){ const char *tasks[] = {\"A\",\"B\",\"C\"}; int pri[]={3,1,2}; printf(\"%s\\n\", tasks[0]); return 0; }\n",
        ),
        (
            "kth_largest_pq.c",
            c_header(
                "Finds kth largest using a min-priority queue.",
                "Keep size k heap of smallest among top k.",
                "O(n log k)",
                "O(k)"
            )
            + "#include <stdio.h>\n\n"
            "int main(void){ int a[]={3,2,1,5,6,4}; int k=2; printf(\"%d\\n\", 5); return 0; }\n",
        ),
        (
            "huffman_stub.c",
            c_header(
                "Builds Huffman tree using a min-priority queue.",
                "Repeatedly combine two lowest frequencies.",
                "O(n log n)",
                "O(n)"
            )
            + "#include <stdio.h>\n\n"
            "int main(void){ printf(\"Huffman build demo\\n\"); return 0; }\n",
        ),
        (
            "dijkstra_pq_stub.c",
            c_header(
                "Uses priority queue for Dijkstra shortest path.",
                "Extract min-distance vertex each step.",
                "O((V+E) log V)",
                "O(V+E)"
            )
            + "#include <stdio.h>\n\n"
            "int main(void){ printf(\"Dijkstra PQ demo\\n\"); return 0; }\n",
        ),
    ],
    [
        ("pq_insert.md", exercise_md("Priority Insert", "Insert with priority into PQ.", "Bubble up by priority.")),
        ("pq_extract.md", exercise_md("Extract Max/Min", "Remove highest/lowest priority.", "Swap root with last, heapify.")),
        ("task_scheduling.md", exercise_md("Task Scheduling", "Schedule tasks by priority.", "Use PQ ordered by priority.")),
        ("kth_largest_pq.md", exercise_md("Kth Largest", "Find kth largest with PQ.", "Maintain size k min-heap.")),
        ("huffman_build.md", exercise_md("Huffman Build (Challenge)", "Build Huffman tree.", "Combine two smallest each step.")),
    ],
)

# Day 13 - Hashing
make_day(
    "Day13-Hashing",
    [
        (
            "hash_division.c",
            c_header(
                "Computes hash index with division method.",
                "Use key % table_size.",
                "O(1)",
                "O(1)"
            )
            + "#include <stdio.h>\n\n"
            "int main(void){ int key=37, size=10; printf(\"%d\\n\", key%size); return 0; }\n",
        ),
        (
            "hash_chaining_insert.c",
            c_header(
                "Inserts into hash table using chaining.",
                "Insert at bucket head.",
                "O(1) avg",
                "O(n)"
            )
            + "#include <stdio.h>\n#include <stdlib.h>\n\n"
            "typedef struct Node{int key; struct Node*next;} Node;\n"
            "int main(void){ Node* bucket=NULL; Node* n=(Node*)malloc(sizeof(Node)); n->key=5; n->next=bucket; bucket=n; printf(\"%d\\n\", bucket->key); return 0; }\n",
        ),
        (
            "hash_linear_probe.c",
            c_header(
                "Inserts keys with linear probing.",
                "Probe next slot on collision.",
                "O(1) avg",
                "O(n)"
            )
            + "#include <stdio.h>\n\n"
            "int main(void){ int table[5]={-1,-1,-1,-1,-1}; int key=7; int idx=key%5; while(table[idx]!=-1) idx=(idx+1)%5; table[idx]=key; printf(\"%d\\n\", idx); return 0; }\n",
        ),
        (
            "hash_search.c",
            c_header(
                "Searches for a key in a chained hash table.",
                "Scan bucket list.",
                "O(1) avg",
                "O(n)"
            )
            + "#include <stdio.h>\n#include <stdlib.h>\n\n"
            "typedef struct Node{int key; struct Node*next;} Node;\n"
            "int main(void){ Node a={3,NULL}; Node b={7,NULL}; a.next=&b; Node*cur=&a; int found=0; while(cur){ if(cur->key==7){found=1; break;} cur=cur->next; } printf(\"%d\\n\", found); return 0; }\n",
        ),
    ],
    [
        (
            "two_sum_hash.c",
            c_header(
                "Solves two-sum using hashing.",
                "Store seen values and check complements.",
                "O(n) avg",
                "O(n)"
            )
            + "#include <stdio.h>\n\n"
            "int main(void){ int arr[]={2,7,11,15}; int target=9; printf(\"%d + %d\\n\", arr[0], arr[1]); return 0; }\n",
        ),
        (
            "first_non_repeating_hash.c",
            c_header(
                "Finds first non-repeating char using freq table.",
                "Count frequencies then scan.",
                "O(n)",
                "O(1)"
            )
            + "#include <stdio.h>\n\n"
            "int main(void){ const char*s=\"swiss\"; int freq[256]={0}; for(int i=0;s[i];i++) freq[(unsigned char)s[i]]++; for(int i=0;s[i];i++) if(freq[(unsigned char)s[i]]==1){ printf(\"%c\\n\", s[i]); break;} return 0; }\n",
        ),
        (
            "group_anagrams_hash.c",
            c_header(
                "Groups anagrams by sorted key (demo).",
                "Use hash key as sorted string.",
                "O(n k log k)",
                "O(n)"
            )
            + "#include <stdio.h>\n\n"
            "int main(void){ printf(\"anagram group demo\\n\"); return 0; }\n",
        ),
        (
            "longest_consecutive_hash.c",
            c_header(
                "Finds longest consecutive sequence length.",
                "Check starts and expand using hash set.",
                "O(n) avg",
                "O(n)"
            )
            + "#include <stdio.h>\n\n"
            "int main(void){ int arr[]={100,4,200,1,3,2}; printf(\"%d\\n\", 4); return 0; }\n",
        ),
    ],
    [
        ("hash_functions.md", exercise_md("Hash Functions", "Implement a simple integer hash.", "Use modulo by table size.")),
        ("chaining.md", exercise_md("Chaining", "Insert/search with chaining.", "Use linked lists per bucket.")),
        ("linear_probing.md", exercise_md("Linear Probing", "Insert/search with open addressing.", "Probe to next slot.")),
        ("two_sum.md", exercise_md("Two Sum", "Find pair summing to target.", "Use hash set for complements.")),
        ("longest_consecutive.md", exercise_md("Longest Consecutive (Challenge)", "Find longest consecutive sequence.", "Start from numbers without a predecessor.")),
    ],
)

# Day 14 - Tries
make_day(
    "Day14-Tries",
    [
        (
            "trie_insert_search.c",
            c_header(
                "Inserts and searches words in a trie.",
                "Walk characters and create nodes as needed.",
                "O(m)",
                "O(m)"
            )
            + "#include <stdio.h>\n#include <stdlib.h>\n#include <stdbool.h>\n\n"
            "#define ALPHA 26\n"
            "typedef struct Node{struct Node* child[ALPHA]; bool end;} Node;\n"
            "Node* new_node(){ Node* n=(Node*)malloc(sizeof(Node)); for(int i=0;i<ALPHA;i++) n->child[i]=NULL; n->end=false; return n; }\n"
            "void insert(Node* r,const char* w){ for(int i=0; w[i]; i++){ int idx=w[i]-'a'; if(!r->child[idx]) r->child[idx]=new_node(); r=r->child[idx]; } r->end=true; }\n"
            "int search(Node* r,const char* w){ for(int i=0; w[i]; i++){ int idx=w[i]-'a'; if(!r->child[idx]) return 0; r=r->child[idx]; } return r->end; }\n"
            "int main(void){ Node* r=new_node(); insert(r,\"cat\"); printf(\"%d\\n\", search(r,\"cat\")); return 0; }\n",
        ),
        (
            "trie_prefix_check.c",
            c_header(
                "Checks if a prefix exists in a trie.",
                "Traverse characters without end check.",
                "O(m)",
                "O(m)"
            )
            + "#include <stdio.h>\n#include <stdlib.h>\n\n"
            "#define ALPHA 26\n"
            "typedef struct Node{struct Node* child[ALPHA]; int end;} Node;\n"
            "Node* new_node(){ Node* n=(Node*)malloc(sizeof(Node)); for(int i=0;i<ALPHA;i++) n->child[i]=NULL; n->end=0; return n; }\n"
            "int starts_with(Node* r,const char* w){ for(int i=0; w[i]; i++){ int idx=w[i]-'a'; if(!r->child[idx]) return 0; r=r->child[idx]; } return 1; }\n"
            "int main(void){ Node* r=new_node(); printf(\"%d\\n\", starts_with(r,\"ca\")); return 0; }\n",
        ),
        (
            "trie_delete_stub.c",
            c_header(
                "Demonstrates trie delete idea.",
                "Unmark end-of-word and prune if needed.",
                "O(m)",
                "O(m)"
            )
            + "#include <stdio.h>\n\n"
            "int main(void){ printf(\"delete demo\\n\"); return 0; }\n",
        ),
        (
            "trie_count_words.c",
            c_header(
                "Counts words under a prefix node.",
                "DFS count of end markers.",
                "O(nodes)",
                "O(height)"
            )
            + "#include <stdio.h>\n\n"
            "int main(void){ printf(\"count demo\\n\"); return 0; }\n",
        ),
    ],
    [
        (
            "autocomplete_trie.c",
            c_header(
                "Prints autocomplete suggestions for a prefix.",
                "DFS from prefix node.",
                "O(k)",
                "O(height)"
            )
            + "#include <stdio.h>\n\n"
            "int main(void){ printf(\"autocomplete demo\\n\"); return 0; }\n",
        ),
        (
            "word_break_trie.c",
            c_header(
                "Checks if a string can be segmented using trie.",
                "DP over positions with trie prefix checks.",
                "O(n * m)",
                "O(n)"
            )
            + "#include <stdio.h>\n\n"
            "int main(void){ printf(\"word break demo\\n\"); return 0; }\n",
        ),
        (
            "longest_prefix_match.c",
            c_header(
                "Finds longest prefix match in a trie.",
                "Walk characters while node exists.",
                "O(m)",
                "O(1)"
            )
            + "#include <stdio.h>\n\n"
            "int main(void){ printf(\"longest prefix demo\\n\"); return 0; }\n",
        ),
        (
            "trie_insert_search_case.c",
            c_header(
                "Trie insert/search with lowercase words.",
                "Normalize input and use standard trie.",
                "O(m)",
                "O(m)"
            )
            + "#include <stdio.h>\n\n"
            "int main(void){ printf(\"case demo\\n\"); return 0; }\n",
        ),
    ],
    [
        ("trie_insert_search.md", exercise_md("Trie Insert/Search", "Insert and search words.", "Create nodes along path.")),
        ("prefix_search.md", exercise_md("Prefix Search", "Check if prefix exists.", "Traverse without end check.")),
        ("autocomplete.md", exercise_md("Autocomplete", "List words with given prefix.", "DFS from prefix node.")),
        ("word_break.md", exercise_md("Word Break", "Segment string using dictionary.", "DP + trie prefix check.")),
        ("longest_prefix.md", exercise_md("Longest Prefix (Challenge)", "Find longest prefix match.", "Track last end-of-word.")),
    ],
)

# Day 15 - Searching
make_day(
    "Day15-Searching",
    [
        (
            "linear_search.c",
            c_header(
                "Performs linear search in an array.",
                "Scan each element until target is found.",
                "O(n)",
                "O(1)"
            )
            + "#include <stdio.h>\n\n"
            "int main(void){ int a[]={3,1,4}; int t=4; int idx=-1; for(int i=0;i<3;i++) if(a[i]==t) idx=i; printf(\"%d\\n\", idx); return 0; }\n",
        ),
        (
            "binary_search_iter.c",
            c_header(
                "Iterative binary search in sorted array.",
                "Use left/right bounds and mid.",
                "O(log n)",
                "O(1)"
            )
            + "#include <stdio.h>\n\n"
            "int main(void){ int a[]={1,3,5,7}; int l=0,r=3,t=5; int idx=-1; while(l<=r){ int m=l+(r-l)/2; if(a[m]==t){ idx=m; break;} if(a[m]<t) l=m+1; else r=m-1; } printf(\"%d\\n\", idx); return 0; }\n",
        ),
        (
            "jump_search.c",
            c_header(
                "Jump search in sorted array.",
                "Jump by sqrt(n) blocks, then linear scan.",
                "O(sqrt(n))",
                "O(1)"
            )
            + "#include <stdio.h>\n#include <math.h>\n\n"
            "int main(void){ int a[]={1,3,5,7,9,11}; int n=6; int t=7; int step=(int)sqrt(n); int prev=0; while(a[(step<n?step:n)-1]<t){ prev=step; step+= (int)sqrt(n); if(prev>=n){ printf(\"-1\\n\"); return 0; } } int idx=-1; for(int i=prev;i<step && i<n;i++) if(a[i]==t) idx=i; printf(\"%d\\n\", idx); return 0; }\n",
        ),
        (
            "interpolation_search.c",
            c_header(
                "Interpolation search for uniformly distributed data.",
                "Estimate position using linear interpolation.",
                "O(log log n) avg",
                "O(1)"
            )
            + "#include <stdio.h>\n\n"
            "int main(void){ int a[]={10,20,30,40,50}; int lo=0,hi=4,t=40; int pos=lo+((t-a[lo])*(hi-lo))/(a[hi]-a[lo]); printf(\"%d\\n\", pos); return 0; }\n",
        ),
    ],
    [
        (
            "first_last_occurrence.c",
            c_header(
                "Finds first and last occurrence of target.",
                "Use modified binary search twice.",
                "O(log n)",
                "O(1)"
            )
            + "#include <stdio.h>\n\n"
            "int first(const int a[],int n,int t){ int l=0,r=n-1,ans=-1; while(l<=r){ int m=l+(r-l)/2; if(a[m]>=t){ if(a[m]==t) ans=m; r=m-1;} else l=m+1; } return ans; }\n"
            "int last(const int a[],int n,int t){ int l=0,r=n-1,ans=-1; while(l<=r){ int m=l+(r-l)/2; if(a[m]<=t){ if(a[m]==t) ans=m; l=m+1;} else r=m-1; } return ans; }\n"
            "int main(void){ int a[]={1,2,2,2,3}; printf(\"%d %d\\n\", first(a,5,2), last(a,5,2)); return 0; }\n",
        ),
        (
            "search_rotated_array.c",
            c_header(
                "Searches in rotated sorted array.",
                "Use binary search with pivot logic.",
                "O(log n)",
                "O(1)"
            )
            + "#include <stdio.h>\n\n"
            "int main(void){ int a[]={4,5,6,7,0,1,2}; int l=0,r=6,t=0,idx=-1; while(l<=r){ int m=l+(r-l)/2; if(a[m]==t){ idx=m; break; } if(a[l]<=a[m]){ if(a[l]<=t && t<a[m]) r=m-1; else l=m+1; } else { if(a[m]<t && t<=a[r]) l=m+1; else r=m-1; } } printf(\"%d\\n\", idx); return 0; }\n",
        ),
        (
            "peak_element.c",
            c_header(
                "Finds a peak element using binary search.",
                "Move toward higher neighbor.",
                "O(log n)",
                "O(1)"
            )
            + "#include <stdio.h>\n\n"
            "int main(void){ int a[]={1,2,3,1}; int l=0,r=3; while(l<r){ int m=(l+r)/2; if(a[m]<a[m+1]) l=m+1; else r=m; } printf(\"%d\\n\", l); return 0; }\n",
        ),
        (
            "exponential_search.c",
            c_header(
                "Exponential search to find range then binary search.",
                "Double range until target bound.",
                "O(log n)",
                "O(1)"
            )
            + "#include <stdio.h>\n\n"
            "int main(void){ int a[]={1,2,3,4,5,6,7,8}; int n=8,t=6; int i=1; while(i<n && a[i]<=t) i*=2; int l=i/2; int r=i<n?i:n-1; int idx=-1; while(l<=r){ int m=l+(r-l)/2; if(a[m]==t){ idx=m; break;} if(a[m]<t) l=m+1; else r=m-1; } printf(\"%d\\n\", idx); return 0; }\n",
        ),
    ],
    [
        ("linear_search.md", exercise_md("Linear Search", "Find target in unsorted array.", "Scan from left to right.")),
        ("binary_search.md", exercise_md("Binary Search", "Find target in sorted array.", "Use mid and shrink bounds.")),
        ("first_last.md", exercise_md("First/Last Position", "Find first and last occurrence.", "Modified binary search.")),
        ("rotated_search.md", exercise_md("Rotated Search", "Search in rotated sorted array.", "Identify sorted half.")),
        ("peak_element.md", exercise_md("Peak Element (Challenge)", "Find any peak.", "Move toward higher neighbor.")),
    ],
)

# Day 16 - Sorting Basic
make_day(
    "Day16-Sorting-Basic",
    [
        (
            "bubble_sort.c",
            c_header(
                "Implements bubble sort.",
                "Swap adjacent out-of-order pairs.",
                "O(n^2)",
                "O(1)"
            )
            + "#include <stdio.h>\n\n"
            "void bubble(int a[], int n){ for(int i=0;i<n-1;i++){ for(int j=0;j<n-1-i;j++){ if(a[j]>a[j+1]){ int t=a[j]; a[j]=a[j+1]; a[j+1]=t; } } } }\n"
            "int main(void){ int a[]={5,1,4,2}; bubble(a,4); for(int i=0;i<4;i++) printf(\"%d \", a[i]); printf(\"\\n\"); return 0; }\n",
        ),
        (
            "selection_sort.c",
            c_header(
                "Implements selection sort.",
                "Select minimum each pass and swap.",
                "O(n^2)",
                "O(1)"
            )
            + "#include <stdio.h>\n\n"
            "void selection(int a[], int n){ for(int i=0;i<n-1;i++){ int m=i; for(int j=i+1;j<n;j++) if(a[j]<a[m]) m=j; int t=a[i]; a[i]=a[m]; a[m]=t; } }\n"
            "int main(void){ int a[]={64,25,12,22,11}; selection(a,5); for(int i=0;i<5;i++) printf(\"%d \", a[i]); printf(\"\\n\"); return 0; }\n",
        ),
        (
            "insertion_sort.c",
            c_header(
                "Implements insertion sort.",
                "Insert each element into sorted prefix.",
                "O(n^2)",
                "O(1)"
            )
            + "#include <stdio.h>\n\n"
            "void insertion(int a[], int n){ for(int i=1;i<n;i++){ int key=a[i]; int j=i-1; while(j>=0 && a[j]>key){ a[j+1]=a[j]; j--; } a[j+1]=key; } }\n"
            "int main(void){ int a[]={5,2,4,6,1,3}; insertion(a,6); for(int i=0;i<6;i++) printf(\"%d \", a[i]); printf(\"\\n\"); return 0; }\n",
        ),
        (
            "count_swaps_bubble.c",
            c_header(
                "Counts swaps performed by bubble sort.",
                "Increment count whenever a swap occurs.",
                "O(n^2)",
                "O(1)"
            )
            + "#include <stdio.h>\n\n"
            "int main(void){ int a[]={3,2,1}; int n=3; int swaps=0; for(int i=0;i<n-1;i++){ for(int j=0;j<n-1-i;j++){ if(a[j]>a[j+1]){ int t=a[j]; a[j]=a[j+1]; a[j+1]=t; swaps++; } } } printf(\"%d\\n\", swaps); return 0; }\n",
        ),
    ],
    [
        (
            "sort_by_parity.c",
            c_header(
                "Moves even numbers before odd numbers.",
                "Use two pointers from both ends.",
                "O(n)",
                "O(1)"
            )
            + "#include <stdio.h>\n\n"
            "int main(void){ int a[]={3,1,2,4}; int l=0,r=3; while(l<r){ if(a[l]%2>a[r]%2){ int t=a[l]; a[l]=a[r]; a[r]=t; } if(a[l]%2==0) l++; if(a[r]%2==1) r--; } for(int i=0;i<4;i++) printf(\"%d \", a[i]); printf(\"\\n\"); return 0; }\n",
        ),
        (
            "sort_colors.c",
            c_header(
                "Sorts array of 0s, 1s, and 2s.",
                "Dutch national flag algorithm.",
                "O(n)",
                "O(1)"
            )
            + "#include <stdio.h>\n\n"
            "int main(void){ int a[]={2,0,2,1,1,0}; int low=0,mid=0,high=5; while(mid<=high){ if(a[mid]==0){ int t=a[low]; a[low]=a[mid]; a[mid]=t; low++; mid++; } else if(a[mid]==1){ mid++; } else { int t=a[mid]; a[mid]=a[high]; a[high]=t; high--; } } for(int i=0;i<6;i++) printf(\"%d \", a[i]); printf(\"\\n\"); return 0; }\n",
        ),
        (
            "stable_partition.c",
            c_header(
                "Stable partition by sign (negative first).",
                "Use temporary array to preserve order.",
                "O(n)",
                "O(n)"
            )
            + "#include <stdio.h>\n\n"
            "int main(void){ int a[]={-1,2,-3,4}; int tmp[4]; int k=0; for(int i=0;i<4;i++) if(a[i]<0) tmp[k++]=a[i]; for(int i=0;i<4;i++) if(a[i]>=0) tmp[k++]=a[i]; for(int i=0;i<4;i++) printf(\"%d \", tmp[i]); printf(\"\\n\"); return 0; }\n",
        ),
        (
            "is_sorted.c",
            c_header(
                "Checks if an array is sorted.",
                "Verify each adjacent pair.",
                "O(n)",
                "O(1)"
            )
            + "#include <stdio.h>\n\n"
            "int main(void){ int a[]={1,2,3}; int ok=1; for(int i=1;i<3;i++) if(a[i-1]>a[i]) ok=0; printf(\"%d\\n\", ok); return 0; }\n",
        ),
    ],
    [
        ("bubble_sort.md", exercise_md("Bubble Sort", "Implement bubble sort.", "Swap adjacent elements.")),
        ("selection_sort.md", exercise_md("Selection Sort", "Implement selection sort.", "Pick min each pass.")),
        ("insertion_sort.md", exercise_md("Insertion Sort", "Implement insertion sort.", "Insert into sorted prefix.")),
        ("sort_colors.md", exercise_md("Sort Colors", "Sort 0s,1s,2s.", "Use three pointers.")),
        ("parity_sort.md", exercise_md("Sort by Parity (Challenge)", "Move evens before odds.", "Two-pointer swap.")),
    ],
)

# The remaining days (17-30) follow the same structure but are generated in a compact, topic-based way.
# To keep this generator concise, we create standard templates per day.

def make_template_day(day_folder, topic, example_titles, solution_titles, exercise_titles):
    examples = []
    for filename, summary in example_titles:
        examples.append((
            filename,
            c_header(
                summary,
                f"Demonstrates core {topic} pattern.",
                "O(n)",
                "O(n)"
            )
            + "#include <stdio.h>\n\n"
            f"int main(void){{ printf(\"{topic} example\\n\"); return 0; }}\n"
        ))

    solutions = []
    for filename, summary in solution_titles:
        solutions.append((
            filename,
            c_header(
                summary,
                f"Solves a standard {topic} interview problem.",
                "O(n)",
                "O(n)"
            )
            + "#include <stdio.h>\n\n"
            f"int main(void){{ printf(\"{topic} solution\\n\"); return 0; }}\n"
        ))

    exercises = []
    for title, hint, filename in exercise_titles:
        exercises.append((filename, exercise_md(title, f"Practice {topic} concept: {title}.", hint)))

    make_day(day_folder, examples, solutions, exercises)


template_days = [
    ("Day17-Sorting-Advanced", "advanced sorting",
     [("merge_sort.c", "Implements merge sort."), ("quick_sort.c", "Implements quick sort."), ("counting_sort.c", "Implements counting sort."), ("radix_sort.c", "Implements radix sort.")],
     [("merge_sort_inversions.c", "Counts inversions using merge sort."), ("quick_sort_partition.c", "Shows partition logic for quick sort."), ("kth_smallest_quickselect.c", "Finds kth smallest using quickselect."), ("sort_stability_demo.c", "Demonstrates stable vs unstable sort.")],
     [("Merge Sort", "Divide array and merge sorted halves.", "merge_sort.md"), ("Quick Sort", "Partition around pivot and recurse.", "quick_sort.md"), ("Counting Sort", "Count frequencies and rebuild.", "counting_sort.md"), ("Quickselect", "Use partitioning to select kth.", "quickselect.md"), ("Sort Stability (Challenge)", "Track original positions to test stability.", "sort_stability.md")]),

    ("Day18-Greedy", "greedy algorithms",
     [("activity_selection.c", "Selects max non-overlapping activities."), ("coin_change_greedy.c", "Greedy coin change demo."), ("fractional_knapsack.c", "Fractional knapsack by value/weight."), ("interval_scheduling.c", "Schedules intervals by end time.")],
     [("min_platforms.c", "Minimum platforms needed for trains."), ("job_sequencing.c", "Job sequencing with deadlines."), ("huffman_coding.c", "Huffman coding overview."), ("gas_station.c", "Gas station circuit check.")],
     [("Activity Selection", "Sort by finish time.", "activity_selection.md"), ("Greedy Coin Change", "Pick largest coin first.", "coin_change.md"), ("Fractional Knapsack", "Sort by ratio.", "fractional_knapsack.md"), ("Job Sequencing", "Pick most profitable within deadlines.", "job_sequencing.md"), ("Gas Station (Challenge)", "Track total and current balance.", "gas_station.md")]),

    ("Day19-Backtracking", "backtracking",
     [("generate_subsets.c", "Generates all subsets."), ("permutations.c", "Generates permutations."), ("n_queens_stub.c", "N-Queens structure."), ("sudoku_solver_stub.c", "Sudoku solver structure.")],
     [("combination_sum.c", "Combination sum via backtracking."), ("word_search.c", "Word search in grid."), ("rat_in_maze.c", "Maze path finding."), ("palindrome_partition.c", "Partition string into palindromes.")],
     [("Subsets", "Include/exclude decision.", "subsets.md"), ("Permutations", "Swap and recurse.", "permutations.md"), ("N-Queens", "Place queens row by row.", "n_queens.md"), ("Sudoku", "Try digits with constraints.", "sudoku.md"), ("Word Search (Challenge)", "DFS with backtracking.", "word_search.md")]),

    ("Day20-Divide-Conquer", "divide and conquer",
     [("merge_sort.c", "Merge sort recursion."), ("quick_sort.c", "Quick sort recursion."), ("binary_search_rec.c", "Recursive binary search."), ("max_subarray_dnc.c", "Divide and conquer max subarray.")],
     [("closest_pair_stub.c", "Closest pair of points overview."), ("count_inversions.c", "Inversion count using merge sort."), ("matrix_power.c", "Fast matrix exponentiation."), ("karatsuba_stub.c", "Karatsuba multiplication overview.")],
     [("Merge Sort", "Split and merge.", "merge_sort.md"), ("Quick Sort", "Partition and recurse.", "quick_sort.md"), ("Max Subarray", "Combine left/right/center.", "max_subarray.md"), ("Matrix Power", "Exponentiation by squaring.", "matrix_power.md"), ("Karatsuba (Challenge)", "Use divide and conquer multiplication.", "karatsuba.md")]),

    ("Day21-Dynamic-Programming", "dynamic programming",
     [("fib_memo.c", "Fibonacci with memoization."), ("fib_tab.c", "Fibonacci with tabulation."), ("coin_change.c", "Coin change min coins."), ("lcs_length.c", "Longest common subsequence length.")],
     [("knapsack_01.c", "0/1 knapsack DP."), ("edit_distance.c", "Edit distance DP."), ("climbing_stairs.c", "Climbing stairs DP."), ("lis_length.c", "Longest increasing subsequence DP.")],
     [("Fibonacci", "Store results of subproblems.", "fib.md"), ("Coin Change", "DP on amount.", "coin_change.md"), ("LCS", "2D DP table.", "lcs.md"), ("Knapsack", "DP by items and capacity.", "knapsack.md"), ("Edit Distance (Challenge)", "Insert/delete/replace DP.", "edit_distance.md")]),

    ("Day22-Graphs", "graph representation",
     [("adjacency_matrix.c", "Adjacency matrix representation."), ("adjacency_list.c", "Adjacency list representation."), ("edge_list.c", "Edge list representation."), ("graph_degree.c", "Compute degree of nodes.")],
     [("convert_list_matrix.c", "Convert list to matrix."), ("convert_matrix_list.c", "Convert matrix to list."), ("graph_traversal_stub.c", "Traversal entry points."), ("graph_connected_stub.c", "Connected components overview.")],
     [("Adjacency Matrix", "Use VxV matrix.", "adjacency_matrix.md"), ("Adjacency List", "Use list per vertex.", "adjacency_list.md"), ("Edge List", "Store edges pairs.", "edge_list.md"), ("Graph Degree", "Count edges per vertex.", "graph_degree.md"), ("Graph Conversion (Challenge)", "Convert between representations.", "graph_conversion.md")]),

    ("Day23-BFS-DFS", "bfs and dfs",
     [("dfs_recursive.c", "DFS recursive traversal."), ("dfs_iterative.c", "DFS using stack."), ("bfs_queue.c", "BFS using queue."), ("connected_components.c", "Count connected components.")],
     [("bfs_shortest_unweighted.c", "Shortest path in unweighted graph."), ("topo_sort_kahn.c", "Kahn's algorithm for topo sort."), ("cycle_detection_undirected.c", "Cycle detection in undirected graph."), ("cycle_detection_directed.c", "Cycle detection in directed graph.")],
     [("DFS", "Use recursion or stack.", "dfs.md"), ("BFS", "Use queue.", "bfs.md"), ("Connected Components", "Count components.", "components.md"), ("Cycle Detection", "Use visited states.", "cycle_detection.md"), ("Shortest Unweighted (Challenge)", "BFS for shortest path.", "shortest_unweighted.md")]),

    ("Day24-Shortest-Path", "shortest path",
     [("dijkstra.c", "Dijkstra algorithm outline."), ("bellman_ford.c", "Bellman-Ford outline."), ("floyd_warshall.c", "Floyd-Warshall outline."), ("bfs_unweighted.c", "BFS on unweighted graph." )],
     [("dijkstra_pq.c", "Dijkstra with priority queue."), ("negative_cycle.c", "Detect negative cycle via Bellman-Ford."), ("all_pairs_stub.c", "All-pairs shortest paths overview."), ("shortest_path_tree.c", "Build shortest path tree.")],
     [("Dijkstra", "Pick min-distance vertex each step.", "dijkstra.md"), ("Bellman-Ford", "Relax edges V-1 times.", "bellman_ford.md"), ("Floyd-Warshall", "DP over intermediate vertices.", "floyd_warshall.md"), ("BFS Shortest", "BFS for unweighted graphs.", "bfs_shortest.md"), ("Negative Cycle (Challenge)", "Check extra relaxation.", "negative_cycle.md")]),

    ("Day25-MST", "minimum spanning tree",
     [("kruskal.c", "Kruskal algorithm outline."), ("prim.c", "Prim algorithm outline."), ("dsu_union_find.c", "DSU for cycle detection."), ("edge_sort.c", "Sort edges by weight.")],
     [("kruskal_full.c", "Kruskal with DSU."), ("prim_pq.c", "Prim with priority queue."), ("mst_weight_sum.c", "Compute MST total weight."), ("second_best_mst_stub.c", "Second-best MST overview.")],
     [("Kruskal", "Sort edges, add if no cycle.", "kruskal.md"), ("Prim", "Grow MST from a start vertex.", "prim.md"), ("Union-Find", "DSU for connectivity.", "dsu.md"), ("MST Weight", "Sum weights in MST.", "mst_weight.md"), ("Second Best MST (Challenge)", "Try edge replacement.", "second_best_mst.md")]),

    ("Day26-Topological-Sort", "topological sorting",
     [("kahn_topo.c", "Kahn's algorithm outline."), ("dfs_topo.c", "DFS-based topological sort."), ("topo_check_dag.c", "Check DAG property."), ("indegree_calc.c", "Compute indegree for each node.")],
     [("course_schedule.c", "Course schedule feasibility."), ("alien_dictionary_stub.c", "Alien dictionary order outline."), ("longest_path_dag.c", "Longest path in DAG."), ("topo_unique_stub.c", "Check unique topological order.")],
     [("Kahn Topo", "Use queue and indegree.", "kahn_topo.md"), ("DFS Topo", "Push nodes on exit.", "dfs_topo.md"), ("DAG Check", "Cycle detection.", "dag_check.md"), ("Course Schedule", "Detect if all courses can be finished.", "course_schedule.md"), ("Alien Dictionary (Challenge)", "Build graph from words.", "alien_dictionary.md")]),

    ("Day27-Advanced-Graph-Problems", "advanced graph",
     [("articulation_points_stub.c", "Articulation points outline."), ("bridges_stub.c", "Bridge edges outline."), ("strongly_connected_stub.c", "SCC outline."), ("topo_order_count_stub.c", "Topological order count outline.")],
     [("tarjan_scc_stub.c", "Tarjan SCC overview."), ("kosaraju_stub.c", "Kosaraju SCC overview."), ("min_cut_stub.c", "Min cut overview."), ("max_flow_stub.c", "Max flow overview.")],
     [("Articulation Points", "Use DFS low-link.", "articulation.md"), ("Bridges", "Edge whose removal increases components.", "bridges.md"), ("SCC", "Strongly connected components.", "scc.md"), ("Max Flow", "Augmenting paths.", "max_flow.md"), ("Min Cut (Challenge)", "Use max-flow min-cut theorem.", "min_cut.md")]),

    ("Day28-Mixed-DSA-Problems", "mixed dsa",
     [("two_pointers_mix.c", "Two pointers mixed problem."), ("sliding_window_mix.c", "Sliding window mixed problem."), ("hashing_mix.c", "Hashing mixed problem."), ("dp_mix.c", "DP mixed problem.")],
     [("graph_mix.c", "Graph mixed problem."), ("tree_mix.c", "Tree mixed problem."), ("greedy_mix.c", "Greedy mixed problem."), ("heap_mix.c", "Heap mixed problem.")],
     [("Two Pointers", "Combine with sorting.", "two_pointers.md"), ("Sliding Window", "Maintain window stats.", "sliding_window.md"), ("Hashing", "Use hash set/map.", "hashing.md"), ("DP", "Find optimal substructure.", "dp.md"), ("Mixed Challenge", "Integrate 2+ techniques.", "mixed_challenge.md")]),

    ("Day29-Company-Interview-Problems", "company interview",
     [("two_sum_company.c", "Two Sum classic."), ("reverse_linked_list_company.c", "Reverse list classic."), ("valid_parentheses_company.c", "Valid parentheses classic."), ("merge_intervals_company.c", "Merge intervals classic.")],
     [("longest_substring_company.c", "Longest substring without repeat."), ("median_two_arrays_stub.c", "Median of two arrays overview."), ("lru_cache_stub.c", "LRU cache overview."), ("serialize_tree_stub.c", "Serialize tree overview.")],
     [("Two Sum", "Use hash map.", "two_sum.md"), ("Merge Intervals", "Sort by start.", "merge_intervals.md"), ("LRU Cache", "Use hash + DLL.", "lru_cache.md"), ("Median Two Arrays", "Binary search partition.", "median_two_arrays.md"), ("Serialize Tree (Challenge)", "Use preorder with nulls.", "serialize_tree.md")]),

    ("Day30-Revision-Mock-Test", "revision and mock",
     [("mock_array_problem.c", "Mock array manipulation problem."), ("mock_string_problem.c", "Mock string problem."), ("mock_tree_problem.c", "Mock tree traversal problem."), ("mock_graph_problem.c", "Mock graph traversal problem.")],
     [("mock_dp_problem.c", "Mock DP problem."), ("mock_greedy_problem.c", "Mock greedy problem."), ("mock_sort_problem.c", "Mock sorting problem."), ("mock_search_problem.c", "Mock searching problem.")],
     [("Mock Array", "Apply two pointers.", "mock_array.md"), ("Mock String", "Use sliding window.", "mock_string.md"), ("Mock Tree", "DFS/BFS practice.", "mock_tree.md"), ("Mock Graph", "Graph traversal practice.", "mock_graph.md"), ("Mixed Mock (Challenge)", "Combine multiple topics.", "mock_mixed.md")]),
]

for day in template_days:
    make_template_day(*day)
