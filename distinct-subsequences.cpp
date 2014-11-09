class Solution {
public:
    int numDistinct(string S, string T) {
        int m = S.size(), n = T.size();
        if (n > m || m == 0) return 0;
        vector<int> record(n, 0);
        for (int i = 0; i < m; ++i) {
            int upper_left = 1; /* numDistinct for S[0:i] and T[0:j] */
            for (int j = 0; j < n; ++j) {
                /* calculate numDistinct for S[0:i + 1] and T[0:j + 1]
                 * record[j] now contains numDistinct for S[0:i] and T[0:j+1] */
                int next_upper_left = record[j];
                record[j] = S[i] == T[j] ? upper_left + record[j] : record[j];
                upper_left = next_upper_left;
            }
        }
        return record[n - 1];
    }
};