/*
Overview:
- Validates BST property using min/max bounds.
Approach:
- Each node must be within (min, max).
Complexity:
- Time: O(n)
- Space: O(h)
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

typedef struct Node{int data; struct Node*left,*right;} Node;
Node* node(int v){ Node*n=(Node*)malloc(sizeof(Node)); n->data=v; n->left=n->right=NULL; return n; }
bool valid(Node* r,int min,int max){ if(!r) return true; if(r->data<min||r->data>max) return false; return valid(r->left,min,r->data-1)&&valid(r->right,r->data+1,max); }
int main(void){ Node*r=node(5); r->left=node(2); r->right=node(7); printf("%s\n", valid(r,INT_MIN,INT_MAX)?"yes":"no"); return 0; }
