/*
Overview:
- Finds LCA in a BST.
Approach:
- Move left/right based on key range.
Complexity:
- Time: O(h)
- Space: O(h)
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{int data; struct Node*left,*right;} Node;
Node* node(int v){ Node*n=(Node*)malloc(sizeof(Node)); n->data=v; n->left=n->right=NULL; return n; }
Node* lca(Node* r,int a,int b){ if(!r) return NULL; if(r->data>a && r->data>b) return lca(r->left,a,b); if(r->data<a && r->data<b) return lca(r->right,a,b); return r; }
int main(void){ Node*r=node(8); r->left=node(3); r->right=node(10); Node*ans=lca(r,3,10); printf("%d\n", ans->data); return 0; }
