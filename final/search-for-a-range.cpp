class Solution {
public:
    int find_first_greater_equal(int A[], int n, int target) {
        int left = 0, right = n - 1, mid;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (A[mid] >= target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return left;
    }
    vector<int> searchRange(int A[], int n, int target) {
        int start = find_first_greater_equal(A, n, target);
        int end = find_first_greater_equal(A, n, target + 1) - 1;
        if (start <= end)
            return {start, end};
        else return
            {-1, -1};
    }
};