class Solution {
private:
    struct Square {
        int row;
        int col;
        bool visited;
        Square(int r, int c, bool v) : row(r), col(c), visited(v) {}
    };
public:
    vector<vector<string> > solveNQueens(int n) {
        if (n <= 0) return {};
        vector<vector<string> > result = {};
        vector<string> solution(n, string(n, '.'));
        vector<bool> main_diag_available(2 * n - 1, true);
        vector<bool> anti_diag_available(2 * n - 1, true);
        vector<bool> row_available(n, true);
        stack<Square> dfs_stack;
        for (int i = 0; i < n; ++i) dfs_stack.push(Square(i, 0, false));
        while (!dfs_stack.empty()) {
            Square &square = dfs_stack.top();
            int row = square.row, col = square.col;
            bool solution_found = false;
            bool visited = square.visited;
            if (!visited) {
                square.visited = true; // mark as visited
                solution[row][col] = 'Q';
                row_available[row] = false;
                main_diag_available[row - col + n] = false;
                anti_diag_available[row + col] = false;
                if (col == n - 1) {
                    result.push_back(solution);
                    solution_found = true;
                } else {
                    int j = col + 1;
                    for (int i = 0; i < n; ++i) {
                        if (row_available[i] &&
                            main_diag_available[i - j + n] &&
                            anti_diag_available[i + j])
                            dfs_stack.push(Square(i, j, false));
                    }
                }
            }
            if (visited || solution_found) {
                // backtrack
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