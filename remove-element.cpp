class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int i = 0;
        while (i < n) {
            if (A[i] == elem) {
                swap(A[i], A[n-1]);
                n--;
            } else {
                i++;
            }
        }
        return n;
    }
};