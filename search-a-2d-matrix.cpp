class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int up = 0, down = m - 1,  row;
        int left = 0, right = n - 1, col;
        while (up < down) {
            row = up + (down - up) / 2 + 1;
            if (matrix[row][0] > target) {
                down = row - 1;
            } else if (matrix[row][0] == target) {
                return true;
            } else {
                up = row;
            }
        }
        row = up;
        while (left < right) {
            col = left + (right - left) / 2 + 1;
            if (matrix[row][col] > target) {
                right = col - 1;
            } else if (matrix[row][col] == target) {
                return true;
            } else {
                left = col;
            }
        }
        col = left;
        if (matrix[row][col] == target) {
            return true;
        } else {
            return false;
        }
    }
};