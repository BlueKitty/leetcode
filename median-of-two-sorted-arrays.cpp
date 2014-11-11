/* Solution from https://oj.leetcode.com/discuss/9265/share-my-simple-o-log-m-n-solution-for-your-reference */
class Solution {
public:
    int findKth(int A[], int m, int B[], int n, int k) {
        if (m < n) return findKth(B, n, A, m, k);
        if (n == 0) return A[k - 1];
        if (k == 1) return min(A[0], B[0]);
        int i = min(m, k / 2), j = min(n, k / 2);
        if (A[i - 1] < B[j - 1]) {
            return findKth(A + i, m - i, B, n, k - i);
        } else {
            return findKth(A, m, B + j, n - j, k - j);
        }
    }
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        if ((m + n) % 2 != 0) {
            return findKth(A, m, B, n, (m + n + 1) / 2);
        } else {
            return (findKth(A, m, B, n, (m + n) / 2) +
                    findKth(A, m, B, n, (m + n) / 2 + 1)) / 2.0;
        }
    }
};