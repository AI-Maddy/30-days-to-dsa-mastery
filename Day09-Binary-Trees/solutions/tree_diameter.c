/*
Overview:
- Computes diameter of a binary tree.
Approach:
- Update best diameter as max(left_height + right_height).
Complexity:
- Time: O(n)
- Space: O(h)
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node { int data; struct Node *left, *right; } Node;
Node *node(int v){ Node *n=(Node*)malloc(sizeof(Node)); n->data=v; n->left=n->right=NULL; return n; }
int height(Node *r, int *best){ if(!r) return 0; int lh=height(r->left,best); int rh=height(r->right,best); if(lh+rh>*best) *best=lh+rh; return (lh>rh?lh:rh)+1; }
int main(void){ Node *r=node(1); r->left=node(2); r->right=node(3); int best=0; height(r,&best); printf("%d\n", best); return 0; }
