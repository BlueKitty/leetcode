class Solution {
public:
    bool canJump(int A[], int n) {
        int reachable_limit = 0;
        for (int i = 0; i < n; i++) {
            if (i > reachable_limit) {
                return false;
            }
            reachable_limit = max(reachable_limit, A[i] + i);
            if (reachable_limit >= n - 1) return true;
        }
        return true;
    }
};