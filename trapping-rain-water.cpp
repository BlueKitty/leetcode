class Solution {
public:
    int trap(int A[], int n) {
        int left_projection = 0, right_projection = 0;
        int total_bar = 0;
        int max = 0;
        for (int i = 0; i < n; ++i) {
            total_bar += A[i];
            if (A[i] > max) max = A[i];
            left_projection += max;
        }
        max = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (A[i] > max) max = A[i];
            right_projection += max;
        }
        return (left_projection + right_projection - max * n - total_bar);
    }
};