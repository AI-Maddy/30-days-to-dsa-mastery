/*
Overview:
- Inverts (mirrors) a binary tree.
Approach:
- Swap left and right recursively.
Complexity:
- Time: O(n)
- Space: O(h)
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node { int data; struct Node *left, *right; } Node;
Node *node(int v){ Node *n=(Node*)malloc(sizeof(Node)); n->data=v; n->left=n->right=NULL; return n; }
void invert(Node *r){ if(!r) return; Node *tmp=r->left; r->left=r->right; r->right=tmp; invert(r->left); invert(r->right); }
int main(void){ Node *r=node(1); r->left=node(2); r->right=node(3); invert(r); printf("%d %d\n", r->left->data, r->right->data); return 0; }
