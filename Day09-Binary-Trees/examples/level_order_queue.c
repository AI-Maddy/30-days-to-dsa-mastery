/*
Overview:
- Prints level-order traversal using a queue.
Approach:
- Use a simple array queue for BFS.
Complexity:
- Time: O(n)
- Space: O(n)
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node { int data; struct Node *left, *right; } Node;
Node *node(int v){ Node *n=(Node*)malloc(sizeof(Node)); n->data=v; n->left=n->right=NULL; return n; }
int main(void){ Node *r=node(1); r->left=node(2); r->right=node(3); Node *q[10]; int f=0,b=0; q[b++]=r; while(f<b){ Node *cur=q[f++]; printf("%d ", cur->data); if(cur->left) q[b++]=cur->left; if(cur->right) q[b++]=cur->right; } printf("\n"); return 0; }
