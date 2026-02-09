/*
Overview:
- Sorts array of 0s, 1s, and 2s.
Approach:
- Dutch national flag algorithm.
Complexity:
- Time: O(n)
- Space: O(1)
*/

#include <stdio.h>

int main(void){ int a[]={2,0,2,1,1,0}; int low=0,mid=0,high=5; while(mid<=high){ if(a[mid]==0){ int t=a[low]; a[low]=a[mid]; a[mid]=t; low++; mid++; } else if(a[mid]==1){ mid++; } else { int t=a[mid]; a[mid]=a[high]; a[high]=t; high--; } } for(int i=0;i<6;i++) printf("%d ", a[i]); printf("\n"); return 0; }
