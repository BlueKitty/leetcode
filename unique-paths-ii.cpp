class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid.size();
        if (m == 0) return 0;
        int n = obstacleGrid[0].size();
        if (n == 0) return 0;
        vector<int> num_paths(n, 0);
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1) return 0;
        num_paths[0] = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) continue;
                if (obstacleGrid[i][j] == 1) {
                    num_paths[j] = 0;
                } else {
                    num_paths[j] = (j > 0 ? num_paths[j - 1] : 0) + num_paths[j];
                }
            }
        }
        return num_paths[n - 1];
    }
};