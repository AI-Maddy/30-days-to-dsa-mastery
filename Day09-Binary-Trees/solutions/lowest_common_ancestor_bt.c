/*
Overview:
- Finds LCA in a binary tree.
Approach:
- Recurse to find nodes; current node is LCA if both sides return non-null.
Complexity:
- Time: O(n)
- Space: O(h)
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node { int data; struct Node *left, *right; } Node;
Node *node(int v){ Node *n=(Node*)malloc(sizeof(Node)); n->data=v; n->left=n->right=NULL; return n; }
Node *lca(Node *r, int a, int b){ if(!r) return NULL; if(r->data==a || r->data==b) return r; Node *l=lca(r->left,a,b); Node *rgt=lca(r->right,a,b); if(l && rgt) return r; return l?l:rgt; }
int main(void){ Node *r=node(1); r->left=node(2); r->right=node(3); r->left->left=node(4); Node *ans=lca(r,4,3); printf("%d\n", ans?ans->data:-1); return 0; }
