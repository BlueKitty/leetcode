class Solution {
public:
    int maxSubArray(int A[], int n) {
        if (n <= 0) return 0;
        int max_end_last = A[0], max_global = A[0];
        for (int i = 1; i < n; i++) {
            max_end_last = max(max_end_last + A[i], A[i]);
            max_global = max(max_end_last, max_global);
        }
        return max_global;
    }
};