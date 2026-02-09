/*
Overview:
- Stable partition by sign (negative first).
Approach:
- Use temporary array to preserve order.
Complexity:
- Time: O(n)
- Space: O(n)
*/

#include <stdio.h>

int main(void){ int a[]={-1,2,-3,4}; int tmp[4]; int k=0; for(int i=0;i<4;i++) if(a[i]<0) tmp[k++]=a[i]; for(int i=0;i<4;i++) if(a[i]>=0) tmp[k++]=a[i]; for(int i=0;i<4;i++) printf("%d ", tmp[i]); printf("\n"); return 0; }
