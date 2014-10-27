class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int i, j, k;
        for (k = m + n - 1, i = m - 1, j = n - 1; k >= 0; k--) {
            if (i >= 0 && j < 0) {
                // don't need to do anything
                return;
            } else if (i < 0 && j >= 0) {
                A[k] = B[j--];
            } else {
                // i >= 0 and j >= 0
                if (A[i] > B[j]) {
                    A[k] = A[i--];
                } else {
                    A[k] = B[j--];
                }
            }
        }
    }
};