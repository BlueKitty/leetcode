class Solution {
public:
    int jump(int A[], int n) {
        int steps = 0;
        int farest = 0;
        int next_farest = 0;
        for (int i = 0; i < n; ++i) {
            if (i > farest) {
                farest = next_farest;
                steps++;
            }
            next_farest = max(next_farest, i + A[i]);
        }
        return steps;
    }
};