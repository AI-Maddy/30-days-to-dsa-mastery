/*
Overview:
- Finds kth smallest element using inorder traversal.
Approach:
- Count nodes during inorder traversal.
Complexity:
- Time: O(n)
- Space: O(h)
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{int data; struct Node*left,*right;} Node;
Node* node(int v){ Node*n=(Node*)malloc(sizeof(Node)); n->data=v; n->left=n->right=NULL; return n; }
void inorder(Node* r,int k,int *count,int *ans){ if(!r||*count>=k) return; inorder(r->left,k,count,ans); (*count)++; if(*count==k) *ans=r->data; inorder(r->right,k,count,ans); }
int main(void){ Node*r=node(5); r->left=node(2); r->right=node(7); int c=0,a=-1; inorder(r,2,&c,&a); printf("%d\n", a); return 0; }
