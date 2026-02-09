/*
Overview:
- Computes height of a binary tree.
Approach:
- Return 1 + max(height(left), height(right)).
Complexity:
- Time: O(n)
- Space: O(h)
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node { int data; struct Node *left, *right; } Node;
Node *node(int v){ Node *n=(Node*)malloc(sizeof(Node)); n->data=v; n->left=n->right=NULL; return n; }
int height(Node *r){ if(!r) return 0; int lh=height(r->left); int rh=height(r->right); return (lh>rh?lh:rh)+1; }
int main(void){ Node *r=node(1); r->left=node(2); r->left->left=node(3); printf("%d\n", height(r)); return 0; }
