class Solution {
public:
    int find_last_less_than(int A[], int n, int target) {
        int left = 0, right = n - 1, mid;
        while (left <= right) {
            mid = (right + left) / 2;
            if (A[mid] >= target) right = mid - 1;
            else left = mid + 1;
        }
        return right;
    }
    vector<int> searchRange(int A[], int n, int target) {
        int start = find_last_less_than(A, n, target) + 1;
        int end = find_last_less_than(A, n, target + 1);
        if (start <= end) return {start, end};
        else return {-1, -1};
    }
};