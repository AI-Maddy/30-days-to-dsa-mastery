/*
Overview:
- Finds k largest elements using a min-heap.
Approach:
- Maintain heap of size k and replace root when bigger.
Complexity:
- Time: O(n log k)
- Space: O(k)
*/

#include <stdio.h>

void heapify(int a[], int n, int i){ int smallest=i; int l=2*i+1; int r=2*i+2; if(l<n && a[l]<a[smallest]) smallest=l; if(r<n && a[r]<a[smallest]) smallest=r; if(smallest!=i){ int t=a[i]; a[i]=a[smallest]; a[smallest]=t; heapify(a,n,smallest);} }
void build(int a[], int n){ for(int i=n/2-1;i>=0;i--) heapify(a,n,i); }
int main(void){ int a[]={3,2,1,5,6,4}; int k=3; int heap[3]={3,2,1}; build(heap,k); for(int i=k;i<6;i++){ if(a[i]>heap[0]){ heap[0]=a[i]; heapify(heap,k,0);} } for(int i=0;i<k;i++) printf("%d ", heap[i]); printf("\n"); return 0; }
