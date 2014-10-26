class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        sort(S.begin(), S.end());
        int n = S.size();
        vector<vector<int> > result(pow(2, n));
        for (int i = 0; i < pow(2, n); ++i) {
            for (int j = 0; j < n; ++j) {
                if (i & (1 << j)) result[i].push_back(S[j]);
            }
        }
        return result;
    }
};