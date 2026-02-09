/*
Overview:
- Counts nodes in a binary tree.
Approach:
- Return 1 + count(left) + count(right).
Complexity:
- Time: O(n)
- Space: O(h)
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node { int data; struct Node *left, *right; } Node;
Node *node(int v){ Node *n=(Node*)malloc(sizeof(Node)); n->data=v; n->left=n->right=NULL; return n; }
int count(Node *r){ if(!r) return 0; return 1 + count(r->left) + count(r->right); }
int main(void){ Node *r=node(1); r->left=node(2); r->right=node(3); printf("%d\n", count(r)); return 0; }
