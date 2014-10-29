class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        if (matrix.size() == 0) return {};
        int m = matrix.size(), n = matrix[0].size();
        vector<int> result;
        result.reserve(m * n);
        int row_min = 0, row_max = m - 1, col_min = 0, col_max = n - 1;
        while (true) {
            for (int j = col_min; j <= col_max; ++j) result.push_back(matrix[row_min][j]);
            if (++row_min > row_max) break;
            for (int i = row_min; i <= row_max; ++i) result.push_back(matrix[i][col_max]);
            if (col_min > --col_max) break;
            for (int j = col_max; j >= col_min; --j) result.push_back(matrix[row_max][j]);
            if (row_min > --row_max) break;
            for (int i = row_max; i >= row_min; --i) result.push_back(matrix[i][col_min]);
            if (++col_min > col_max) break;
        }
        return result;
    }
};