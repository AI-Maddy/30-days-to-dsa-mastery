/*
Overview:
- Inserts keys with linear probing.
Approach:
- Probe next slot on collision.
Complexity:
- Time: O(1) avg
- Space: O(n)
*/

#include <stdio.h>

int main(void){ int table[5]={-1,-1,-1,-1,-1}; int key=7; int idx=key%5; while(table[idx]!=-1) idx=(idx+1)%5; table[idx]=key; printf("%d\n", idx); return 0; }
