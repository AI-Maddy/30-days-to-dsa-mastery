/*
Overview:
- Finds minimum and maximum in a BST.
Approach:
- Go left for min, right for max.
Complexity:
- Time: O(h)
- Space: O(1)
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{int data; struct Node*left,*right;} Node;
Node* node(int v){ Node*n=(Node*)malloc(sizeof(Node)); n->data=v; n->left=n->right=NULL; return n; }
int min(Node* r){ while(r->left) r=r->left; return r->data; }
int max(Node* r){ while(r->right) r=r->right; return r->data; }
int main(void){ Node*r=node(5); r->left=node(2); r->right=node(9); printf("%d %d\n", min(r), max(r)); return 0; }
