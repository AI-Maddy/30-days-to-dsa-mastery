/*
Overview:
- Iterative binary search in sorted array.
Approach:
- Use left/right bounds and mid.
Complexity:
- Time: O(log n)
- Space: O(1)
*/

#include <stdio.h>

int main(void){ int a[]={1,3,5,7}; int l=0,r=3,t=5; int idx=-1; while(l<=r){ int m=l+(r-l)/2; if(a[m]==t){ idx=m; break;} if(a[m]<t) l=m+1; else r=m-1; } printf("%d\n", idx); return 0; }
