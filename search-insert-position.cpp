class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        int begin = 0;
        int end = n - 1;
        int pivot;
        while(begin <= end) {
            pivot = (begin + end) >> 1;
            if (A[pivot] > target) {
                end = pivot - 1;
            } else if (A[pivot] < target) {
                begin = pivot + 1;
            } else {
                return pivot;
            }
        }
        return A[pivot] > target ? pivot : pivot + 1;
    }
};