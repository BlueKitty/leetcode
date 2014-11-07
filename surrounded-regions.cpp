class Solution {
public:
    void fill(vector<vector<char>> &board, int i, int j) {
        if (board[i][j] != 'O') return;
        int m = board.size();
        int n = board[0].size();
        stack<pair<int, int>> dfs_stack;
        dfs_stack.push(make_pair(i, j));
        while (!dfs_stack.empty()) {
            auto &pos = dfs_stack.top();
            int row = pos.first, col = pos.second;
            if (board[row][col] == 'O') {
                board[row][col] = 'M';
                if (row > 0 && board[row - 1][col] == 'O')
                    dfs_stack.push(make_pair(row - 1, col));
                if (row < m - 1 && board[row + 1][col] == 'O')
                    dfs_stack.push(make_pair(row + 1, col));
                if (col > 0 && board[row][col - 1] == 'O')
                    dfs_stack.push(make_pair(row, col - 1));
                if (col < n - 1 && board[row][col + 1] == 'O')
                    dfs_stack.push(make_pair(row, col + 1));
            } else {
                dfs_stack.pop();
            }
        }
    }
    void solve(vector<vector<char>> &board) {
        int m = board.size();
        if (m == 0) return;
        int n = board[0].size();
        if (n == 0) return;
        for (int i = 0; i < m; ++i) {
            fill(board, i, 0);
            fill(board, i, n - 1);
        }
        for (int j = 0; j < n; ++j) {
            fill(board, 0, j);
            fill(board, m - 1, j);
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O') board[i][j] = 'X';
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'M') board[i][j] = 'O';
            }
        }
    }
};