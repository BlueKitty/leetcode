class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > result(n, vector<int>(n));
        int row_min = 0, row_max = n - 1, col_min = 0, col_max = n - 1;
        int num = 1;
        while (true) {
            for (int j = col_min; j <= col_max; j++) result[row_min][j] = num++;
            if (++row_min > row_max) break;
            for (int i = row_min; i <= row_max; i++) result[i][col_max] = num++;
            if (col_min > --col_max) break;
            for (int j = col_max; j >= col_min; j--) result[row_max][j] = num++;
            if (row_min > --row_max) break;
            for (int i = row_max; i >= row_min; i--) result[i][col_min] = num++;
            if (++col_min > col_max) break;
        }
        return result;
    }
};