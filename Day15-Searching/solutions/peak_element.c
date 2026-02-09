/*
Overview:
- Finds a peak element using binary search.
Approach:
- Move toward higher neighbor.
Complexity:
- Time: O(log n)
- Space: O(1)
*/

#include <stdio.h>

int main(void){ int a[]={1,2,3,1}; int l=0,r=3; while(l<r){ int m=(l+r)/2; if(a[m]<a[m+1]) l=m+1; else r=m; } printf("%d\n", l); return 0; }
