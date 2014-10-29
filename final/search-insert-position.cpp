class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        int left = 0, right = n - 1, mid;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (A[mid] == target) return mid;
            if (A[mid] > target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return left;
    }
};