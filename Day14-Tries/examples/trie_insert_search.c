/*
Overview:
- Inserts and searches words in a trie.
Approach:
- Walk characters and create nodes as needed.
Complexity:
- Time: O(m)
- Space: O(m)
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ALPHA 26
typedef struct Node{struct Node* child[ALPHA]; bool end;} Node;
Node* new_node(){ Node* n=(Node*)malloc(sizeof(Node)); for(int i=0;i<ALPHA;i++) n->child[i]=NULL; n->end=false; return n; }
void insert(Node* r,const char* w){ for(int i=0; w[i]; i++){ int idx=w[i]-'a'; if(!r->child[idx]) r->child[idx]=new_node(); r=r->child[idx]; } r->end=true; }
int search(Node* r,const char* w){ for(int i=0; w[i]; i++){ int idx=w[i]-'a'; if(!r->child[idx]) return 0; r=r->child[idx]; } return r->end; }
int main(void){ Node* r=new_node(); insert(r,"cat"); printf("%d\n", search(r,"cat")); return 0; }
