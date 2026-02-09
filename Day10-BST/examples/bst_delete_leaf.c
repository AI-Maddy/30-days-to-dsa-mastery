/*
Overview:
- Deletes a leaf node in a BST.
Approach:
- Recurse to node; handle child cases.
Complexity:
- Time: O(h)
- Space: O(h)
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{int data; struct Node*left,*right;} Node;
Node* node(int v){ Node*n=(Node*)malloc(sizeof(Node)); n->data=v; n->left=n->right=NULL; return n; }
Node* del(Node* r,int v){ if(!r) return NULL; if(v<r->data) r->left=del(r->left,v); else if(v>r->data) r->right=del(r->right,v); else { if(!r->left && !r->right){ free(r); return NULL; } } return r; }
int main(void){ Node*r=node(5); r->left=node(2); r->right=node(7); r=del(r,2); printf("%d\n", r->left==NULL); return 0; }
