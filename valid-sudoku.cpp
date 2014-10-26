class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        int size = board.size();
        vector<vector<bool> > row_visited(size, vector<bool>(size, false));
        vector<vector<bool> > col_visited(size, vector<bool>(size, false));
        vector<vector<bool> > square_visited(size, vector<bool>(size, false));
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                char value = board[i][j];
                if (value == '.') continue;
                int number = value - '1';
                int square_index = i / 3 + j / 3 * 3;
                if (row_visited[i][number]) return false;
                if (col_visited[j][number]) return false;
                if (square_visited[square_index][number]) return false;
                row_visited[i][number] = true;
                col_visited[j][number] = true;
                square_visited[square_index][number] = true;
            }
        }
        return true;
    }
};