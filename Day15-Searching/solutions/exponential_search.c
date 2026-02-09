/*
Overview:
- Exponential search to find range then binary search.
Approach:
- Double range until target bound.
Complexity:
- Time: O(log n)
- Space: O(1)
*/

#include <stdio.h>

int main(void){ int a[]={1,2,3,4,5,6,7,8}; int n=8,t=6; int i=1; while(i<n && a[i]<=t) i*=2; int l=i/2; int r=i<n?i:n-1; int idx=-1; while(l<=r){ int m=l+(r-l)/2; if(a[m]==t){ idx=m; break;} if(a[m]<t) l=m+1; else r=m-1; } printf("%d\n", idx); return 0; }
