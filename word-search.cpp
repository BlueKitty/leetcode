class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        if (word == "") return true;
        int m = board.size();
        if (m == 0) return false;
        int n = board[0].size();
        stack<pair<int, int>> dfs_stack;
        vector<vector<bool> > visited(m);
        for (int i = 0; i < m; ++i) {
            visited[i].resize(n, false);
            for (int j = 0; j < n; ++j) {
                dfs_stack.push(make_pair(i, j));
            }
        }
        int cur_idx = 0;
        while (!dfs_stack.empty()) {
            int x = dfs_stack.top().first, y = dfs_stack.top().second;
            if (!visited[x][y]) {
                visited[x][y] = true;
                if (board[x][y] == word[cur_idx]) {
                    if (cur_idx == word.size() - 1) return true;
                    if (x > 0 && !visited[x - 1][y]) dfs_stack.push(make_pair(x - 1, y));
                    if (y > 0 && !visited[x][y - 1]) dfs_stack.push(make_pair(x, y - 1));
                    if (x < m - 1 && !visited[x + 1][y]) dfs_stack.push(make_pair(x + 1, y));
                    if (y < n - 1 && !visited[x][y + 1]) dfs_stack.push(make_pair(x, y + 1));
                }
                cur_idx++;
            } else {
                visited[x][y] = false;
                cur_idx--;
                dfs_stack.pop();
            }
        }
        return false;
    }
};