class Solution {
public:
    bool search(int A[], int n, int target) {
        int left = 0, right = n - 1, mid;
        while (left <= right) {
            mid = (left + right) / 2;
            if (target == A[mid]) return true;
            if (A[mid] > A[left]) {
                if (target < A[mid] && target >= A[left]) right = mid - 1;
                else left = mid + 1;
            } else if (A[mid] < A[left]) {
                if (target > A[mid] && target <= A[right]) left = mid + 1;
                else right = mid - 1;
            } else {
                // A[mid] == A[left]
                left++;
            }
        }
        return false;
    }
};