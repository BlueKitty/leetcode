/* A clever solution from Pumbaa, only one pass */
class Solution {
public:
    int trap(int A[], int n) {
        int left = 0, right = n - 1, cur_level = 0, water = 0;
        while (left <= right) {
            if (A[left] <= A[right]) {
                cur_level = max(A[left], cur_level);
                water += (cur_level - A[left++]);
            } else {
                cur_level = max(A[right], cur_level);
                water += (cur_level - A[right--]);
            }
        }
        return water;
    }
};

/* My original solution, two passes */
class Solution {
public:
    int trap(int A[], int n) {
        int left_projection = 0, right_projection = 0, total_bar = 0, max = 0;
        for (int i = 0; i < n; ++i) {
            total_bar += A[i];
            if (A[i] > max) max = A[i];
            left_projection += max;
        }
        max = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (A[i] > max) max = A[i];
            right_projection += max;
        }
        return (left_projection + right_projection - max * n - total_bar);
    }
};