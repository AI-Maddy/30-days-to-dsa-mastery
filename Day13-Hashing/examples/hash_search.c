/*
Overview:
- Searches for a key in a chained hash table.
Approach:
- Scan bucket list.
Complexity:
- Time: O(1) avg
- Space: O(n)
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{int key; struct Node*next;} Node;
int main(void){ Node a={3,NULL}; Node b={7,NULL}; a.next=&b; Node*cur=&a; int found=0; while(cur){ if(cur->key==7){found=1; break;} cur=cur->next; } printf("%d\n", found); return 0; }
