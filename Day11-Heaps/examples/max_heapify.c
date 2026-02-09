/*
Overview:
- Heapifies a subtree in a max-heap.
Approach:
- Compare with children and swap down.
Complexity:
- Time: O(log n)
- Space: O(1)
*/

#include <stdio.h>

void heapify(int a[], int n, int i){ int largest=i; int l=2*i+1; int r=2*i+2; if(l<n && a[l]>a[largest]) largest=l; if(r<n && a[r]>a[largest]) largest=r; if(largest!=i){ int t=a[i]; a[i]=a[largest]; a[largest]=t; heapify(a,n,largest);} }
int main(void){ int a[]={3,9,2,1,4,5}; int n=6; heapify(a,n,0); printf("%d\n", a[0]); return 0; }
