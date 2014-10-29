class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> record(m, 1);
        for (int j = 1; j < n; ++j) {
            for (int i = 1; i < m; ++i) {
                record[i] = record[i - 1] + record[i];
            }
        }
        return record[m - 1];
    }
};