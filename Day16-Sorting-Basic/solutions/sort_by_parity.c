/*
Overview:
- Moves even numbers before odd numbers.
Approach:
- Use two pointers from both ends.
Complexity:
- Time: O(n)
- Space: O(1)
*/

#include <stdio.h>

int main(void){ int a[]={3,1,2,4}; int l=0,r=3; while(l<r){ if(a[l]%2>a[r]%2){ int t=a[l]; a[l]=a[r]; a[r]=t; } if(a[l]%2==0) l++; if(a[r]%2==1) r--; } for(int i=0;i<4;i++) printf("%d ", a[i]); printf("\n"); return 0; }
