class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex + 1, 1);
        for (int i = 2; i <= rowIndex; ++i) {
            // the first two rows are special cases
            // ith row has (i + 1) numbers, we need to update 1 ... i - 1;
            for (int j = i - 1; j >= 1; --j) {
                row[j] += row[j - 1];
            }
        }
        return row;
    }
};