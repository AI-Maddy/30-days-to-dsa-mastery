/*
Overview:
- Performs inorder, preorder, and postorder traversals.
Approach:
- Use recursion to visit nodes in each order.
Complexity:
- Time: O(n)
- Space: O(h)
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node { int data; struct Node *left, *right; } Node;
Node *node(int v){ Node *n=(Node*)malloc(sizeof(Node)); n->data=v; n->left=n->right=NULL; return n; }
void inorder(Node *r){ if(!r) return; inorder(r->left); printf("%d ", r->data); inorder(r->right); }
void preorder(Node *r){ if(!r) return; printf("%d ", r->data); preorder(r->left); preorder(r->right); }
void postorder(Node *r){ if(!r) return; postorder(r->left); postorder(r->right); printf("%d ", r->data); }
int main(void){ Node *r=node(1); r->left=node(2); r->right=node(3); inorder(r); printf("\n"); preorder(r); printf("\n"); postorder(r); printf("\n"); return 0; }
