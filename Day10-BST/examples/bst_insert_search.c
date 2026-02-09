/*
Overview:
- Inserts and searches nodes in a BST.
Approach:
- Recursive insert and search based on key comparison.
Complexity:
- Time: O(h)
- Space: O(h)
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{int data; struct Node*left,*right;} Node;
Node* node(int v){ Node*n=(Node*)malloc(sizeof(Node)); n->data=v; n->left=n->right=NULL; return n; }
Node* insert(Node* r,int v){ if(!r) return node(v); if(v<r->data) r->left=insert(r->left,v); else if(v>r->data) r->right=insert(r->right,v); return r; }
Node* search(Node* r,int v){ if(!r||r->data==v) return r; if(v<r->data) return search(r->left,v); return search(r->right,v); }
int main(void){ Node*r=NULL; r=insert(r,5); r=insert(r,2); r=insert(r,8); printf("%s\n", search(r,2)?"found":"no"); return 0; }
