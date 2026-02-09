/*
Overview:
- Extracts max from a max-heap.
Approach:
- Swap root with last, reduce size, heapify.
Complexity:
- Time: O(log n)
- Space: O(1)
*/

#include <stdio.h>

void heapify(int a[], int n, int i){ int largest=i; int l=2*i+1; int r=2*i+2; if(l<n && a[l]>a[largest]) largest=l; if(r<n && a[r]>a[largest]) largest=r; if(largest!=i){ int t=a[i]; a[i]=a[largest]; a[largest]=t; heapify(a,n,largest);} }
int main(void){ int a[]={10,7,5,2,1}; int n=5; int max=a[0]; a[0]=a[n-1]; n--; heapify(a,n,0); printf("%d\n", max); return 0; }
