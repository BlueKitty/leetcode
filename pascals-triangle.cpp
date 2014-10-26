class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > triangle;
        for (int i = 0; i < numRows; i++) {
            vector<int> newRow;
            for (int j = 0; j < i + 1; j++) {
                if (j == 0) {
                    // first one
                    newRow.push_back(1);
                } else if (j == i) {
                    // last one
                    newRow.push_back(1);
                } else {
                    newRow.push_back(triangle[i - 1][j - 1] + triangle[i - 1][j]);
                }
            }
            triangle.push_back(newRow);
        }
        return triangle;
    }
};