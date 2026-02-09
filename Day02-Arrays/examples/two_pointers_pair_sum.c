/*
Overview:
- Finds a pair with a given sum in a sorted array using two pointers.
Approach:
- Move left/right pointers based on current sum.
Complexity:
- Time: O(n)
- Space: O(1)
*/

#include <stdio.h>
#include <stdbool.h>

bool has_pair_sum(const int arr[], int n, int target) {
    int left = 0;
    int right = n - 1;

    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == target) {
            return true;
        }
        if (sum < target) {
            left++;
        } else {
            right--;
        }
    }

    return false;
}

int main(void) {
    int arr[] = {1, 3, 4, 6, 8, 10};
    int n = (int)(sizeof(arr) / sizeof(arr[0]));

    int target = 14;
    printf("Has pair sum %d? %s\n", target, has_pair_sum(arr, n, target) ? "yes" : "no");
    return 0;
}
