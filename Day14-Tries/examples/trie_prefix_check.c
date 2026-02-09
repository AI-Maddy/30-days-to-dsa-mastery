/*
Overview:
- Checks if a prefix exists in a trie.
Approach:
- Traverse characters without end check.
Complexity:
- Time: O(m)
- Space: O(m)
*/

#include <stdio.h>
#include <stdlib.h>

#define ALPHA 26
typedef struct Node{struct Node* child[ALPHA]; int end;} Node;
Node* new_node(){ Node* n=(Node*)malloc(sizeof(Node)); for(int i=0;i<ALPHA;i++) n->child[i]=NULL; n->end=0; return n; }
int starts_with(Node* r,const char* w){ for(int i=0; w[i]; i++){ int idx=w[i]-'a'; if(!r->child[idx]) return 0; r=r->child[idx]; } return 1; }
int main(void){ Node* r=new_node(); printf("%d\n", starts_with(r,"ca")); return 0; }
