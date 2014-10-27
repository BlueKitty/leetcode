class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        if (n <= 0) return {};
        vector<vector<string> > result = {};
        vector<string> solution(n, string(n, '.'));
        vector<bool> main_diag_available(2 * n - 1, true);
        vector<bool> anti_diag_available(2 * n - 1, true);
        vector<bool> row_available(n, true);
        stack<tuple<int, int, bool> > dfs_stack;
        for (int i = 0; i < n; ++i) dfs_stack.push(make_tuple(i, 0, false));
        while (!dfs_stack.empty()) {
            auto &square = dfs_stack.top();
            int row = get<0>(square), col = get<1>(square);
            if (!get<2>(square)) {
                get<2>(square) = true; // mark as visited
                solution[row][col] = 'Q';
                row_available[row] = false;
                main_diag_available[row - col + n] = false;
                anti_diag_available[row + col] = false;
                if (col == n - 1) {
                    result.push_back(solution);
                } else {
                    for (int i = 0, j = col + 1; i < n; ++i) {
                        if (row_available[i] &&
                            main_diag_available[i - j + n] &&
                            anti_diag_available[i + j])
                            dfs_stack.push(make_tuple(i, j, false));
                    }
                }
            } else {
                solution[row][col] = '.';
                row_available[row] = true;
                main_diag_available[row - col + n] = true;
                anti_diag_available[row + col] = true;
                dfs_stack.pop();
            }
        }
        return result;
    }
};