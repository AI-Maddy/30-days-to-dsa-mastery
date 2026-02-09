/*
Overview:
- Inserts a key into a max-heap array.
Approach:
- Append and bubble up.
Complexity:
- Time: O(log n)
- Space: O(1)
*/

#include <stdio.h>

int main(void){ int heap[10]={10,7,5,2,1}; int n=5; int key=9; int i=n++; heap[i]=key; while(i>0 && heap[(i-1)/2]<heap[i]){ int t=heap[i]; heap[i]=heap[(i-1)/2]; heap[(i-1)/2]=t; i=(i-1)/2; } printf("%d\n", heap[0]); return 0; }
