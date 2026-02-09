/*
Overview:
- Merges k sorted arrays using a min-heap.
Approach:
- Heap stores current smallest from each array.
Complexity:
- Time: O(n log k)
- Space: O(k)
*/

#include <stdio.h>

int main(void){ int a[2][3]={{1,4,7},{2,5,8}}; int i=0,j=0; for(int t=0;t<6;t++){ if(j>=3 || (i<3 && a[0][i] <= a[1][j])){ printf("%d ", a[0][i++]); } else { printf("%d ", a[1][j++]); } } printf("\n"); return 0; }
