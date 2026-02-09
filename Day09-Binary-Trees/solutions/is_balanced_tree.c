/*
Overview:
- Checks if a tree is height-balanced.
Approach:
- Return -1 on imbalance; otherwise return height.
Complexity:
- Time: O(n)
- Space: O(h)
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node { int data; struct Node *left, *right; } Node;
Node *node(int v){ Node *n=(Node*)malloc(sizeof(Node)); n->data=v; n->left=n->right=NULL; return n; }
int check(Node *r){ if(!r) return 0; int lh=check(r->left); if(lh==-1) return -1; int rh=check(r->right); if(rh==-1) return -1; if(lh-rh>1 || rh-lh>1) return -1; return (lh>rh?lh:rh)+1; }
int main(void){ Node *r=node(1); r->left=node(2); r->left->left=node(3); printf("%s\n", check(r)==-1?"no":"yes"); return 0; }
