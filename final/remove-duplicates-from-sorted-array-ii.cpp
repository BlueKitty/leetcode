class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n == 0) return 0;
        int i = 1, count = 1, prev = A[0];
        for (int j = 1; j < n; j++) {
            if (A[j] == prev) {
                count++;
            } else {
                prev = A[j];
                count = 1;
            }
            if (count <= 2) A[i++] = A[j];
        }
        return i;
    }
};