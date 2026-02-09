/*
Overview:
- Interpolation search for uniformly distributed data.
Approach:
- Estimate position using linear interpolation.
Complexity:
- Time: O(log log n) avg
- Space: O(1)
*/

#include <stdio.h>

int main(void){ int a[]={10,20,30,40,50}; int lo=0,hi=4,t=40; int pos=lo+((t-a[lo])*(hi-lo))/(a[hi]-a[lo]); printf("%d\n", pos); return 0; }
