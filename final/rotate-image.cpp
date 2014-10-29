class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i < m / 2; i++) { // swap top with bottom
            for (int j = 0; j < n; j++) {
                swap(matrix[i][j], matrix[m - 1 - i][j]);
            }
        }
        for (int i = 0; i < m; i++) { // swap top right with bottom left
            for (int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};