class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n <= 0) {
            return 0;
        }
        int i, j;
        int prev = A[0];
        for (i = 1, j = 1; j < n; j++) {
            if (A[j] != prev) {
                A[i++] = A[j];
            }
            prev = A[j];
        }
        return i;
    }
};