/*
Overview:
- Checks if an array satisfies max-heap property.
Approach:
- Each parent must be >= children.
Complexity:
- Time: O(n)
- Space: O(1)
*/

#include <stdio.h>

int is_heap(const int a[], int n){ for(int i=0;i<=n/2-1;i++){ int l=2*i+1, r=2*i+2; if(l<n && a[i]<a[l]) return 0; if(r<n && a[i]<a[r]) return 0; } return 1; }
int main(void){ int a[]={10,7,5,2,1}; printf("%d\n", is_heap(a,5)); return 0; }
