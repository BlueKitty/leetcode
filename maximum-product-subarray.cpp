class Solution {
public:
    int maxProduct(int A[], int n) {
        int max_product = INT_MIN;
        int max_end_last = 1;
        int min_product = INT_MAX;
        int min_end_last = 1;
        for (int i = 0; i < n; ++i) {
            int max_end_here = max(A[i], A[i] * max_end_last);
            max_end_here = max(max_end_here, A[i] * min_end_last);
            int min_end_here = min(A[i], A[i] * min_end_last);
            min_end_here = min(min_end_here, A[i] * max_end_last);
            max_product = max(max_end_here, max_product);
            min_end_last = min_end_here;
            max_end_last = max_end_here;
        }
        return max_product;
    }
};