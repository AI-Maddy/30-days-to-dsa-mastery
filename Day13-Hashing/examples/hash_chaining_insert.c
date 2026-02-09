/*
Overview:
- Inserts into hash table using chaining.
Approach:
- Insert at bucket head.
Complexity:
- Time: O(1) avg
- Space: O(n)
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{int key; struct Node*next;} Node;
int main(void){ Node* bucket=NULL; Node* n=(Node*)malloc(sizeof(Node)); n->key=5; n->next=bucket; bucket=n; printf("%d\n", bucket->key); return 0; }
