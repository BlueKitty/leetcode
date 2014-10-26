class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int m = matrix.size();
        int n = m > 0 ? matrix[0].size() : 0;
        bool first_row_zeroed = false, first_column_zeroed = false;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // mark zeros on first column and first row
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                    if (i == 0) first_row_zeroed = true;
                    if (j == 0) first_column_zeroed = true;
                }
            }
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        if (first_column_zeroed) {
            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
        if (first_row_zeroed) {
            for (int j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }
    }
};