class Solution {
public:
    bool canJump(int A[], int n) {
        if (n == 0) {
            return true;
        }
        int reachable_limit = 0;
        for (int i = 0; i < n; i++) {
            if (i > reachable_limit) {
                return false;
            }
            int max_jump = A[i];
            if (reachable_limit < i + max_jump) {
                reachable_limit = i + max_jump;
            }
            if (reachable_limit >= n - 1) {
                return true;
            }
        }
        // should never get here
        return false;
    }
};