class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> last_column(m, 0);
        last_column[0] = grid[0][0];
        for (int i = 1; i < m; ++i) last_column[i] = last_column[i - 1] + grid[i][0];
        for (int j = 1; j < n; ++j) {
            for (int i = 0; i < m; ++i) {
                int from_left = last_column[i];
                int from_top = i > 0 ? last_column[i - 1] : INT_MAX;
                last_column[i] = min(from_left, from_top) + grid[i][j];
            }
        }
        return last_column[m - 1];
    }
};