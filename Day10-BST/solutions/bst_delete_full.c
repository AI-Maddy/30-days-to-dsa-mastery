/*
Overview:
- Deletes a node in BST with all cases.
Approach:
- Replace with inorder successor for two children.
Complexity:
- Time: O(h)
- Space: O(h)
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{int data; struct Node*left,*right;} Node;
Node* node(int v){ Node*n=(Node*)malloc(sizeof(Node)); n->data=v; n->left=n->right=NULL; return n; }
Node* minNode(Node* r){ while(r && r->left) r=r->left; return r; }
Node* del(Node* r,int v){ if(!r) return NULL; if(v<r->data) r->left=del(r->left,v); else if(v>r->data) r->right=del(r->right,v); else { if(!r->left){ Node* t=r->right; free(r); return t; } if(!r->right){ Node* t=r->left; free(r); return t; } Node* t=minNode(r->right); r->data=t->data; r->right=del(r->right,t->data); } return r; }
int main(void){ Node*r=node(5); r->left=node(2); r->right=node(8); r=del(r,5); printf("%d\n", r->data); return 0; }
