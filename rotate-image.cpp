class Solution {
public:
    void mirror_x(vector<vector<int> > &matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i < m / 2; i++) {
            for (int j = 0; j < n; j++) {
                swap(matrix[i][j], matrix[m - 1 - i][j]);
            }
        }
    }
    void mirror_diag(vector<vector<int> > &matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
    void rotate(vector<vector<int> > &matrix) {
        mirror_x(matrix);
        mirror_diag(matrix);
    }
};