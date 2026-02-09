/*
Overview:
- Finds the maximum area of water that can be trapped between two lines.
Approach:
- Two pointers moving inward based on the shorter height.
Complexity:
- Time: O(n)
- Space: O(1)
*/

#include <stdio.h>

int max_area(const int height[], int n) {
    int left = 0;
    int right = n - 1;
    int best = 0;

    while (left < right) {
        int h = height[left] < height[right] ? height[left] : height[right];
        int width = right - left;
        int area = h * width;

        if (area > best) {
            best = area;
        }

        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }

    return best;
}

int main(void) {
    int height[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int n = (int)(sizeof(height) / sizeof(height[0]));

    printf("Max area = %d\n", max_area(height, n));
    return 0;
}
