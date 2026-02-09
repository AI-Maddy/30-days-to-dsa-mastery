/*
Overview:
- Prints inorder traversal of BST in sorted order.
Approach:
- Inorder traversal visits left, root, right.
Complexity:
- Time: O(n)
- Space: O(h)
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{int data; struct Node*left,*right;} Node;
Node* node(int v){ Node*n=(Node*)malloc(sizeof(Node)); n->data=v; n->left=n->right=NULL; return n; }
void inorder(Node* r){ if(!r) return; inorder(r->left); printf("%d ", r->data); inorder(r->right); }
int main(void){ Node*r=node(5); r->left=node(2); r->right=node(7); inorder(r); printf("\n"); return 0; }
