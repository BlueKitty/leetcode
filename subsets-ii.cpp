class Solution {
public:
    // assume S is an umempty sorted array, check if the bit mask is valid for generating a subset
    bool is_valid(int bit_mask, vector<int> &S) {
        int pre = 0; // the value does not matter
        bool can_set = true;
        for (int i = 0; i < S.size(); ++i) {
            if ((bit_mask & (1 << i)) == 0) {
                // the bit is unset
                can_set = false;
            } else if (S[i] == pre) {
                if (!can_set) return false;
                // bit set and there is occurance of unset bit of that value
            } else {
                // bit set and it is the first occurance of the value
                can_set = true;
            }
            pre = S[i];
        }
        return true;
    }
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        if (S.empty()) return {{}};
        sort(S.begin(), S.end());
        vector<vector<int> > result;
        int n = S.size();
        for (int i = 0; i < pow(2, n); ++i) {
            if (!is_valid(i, S)) continue;
            result.push_back({});
            for (int j = 0; j < n; ++j) {
                if (i & (1 << j)) result.back().push_back(S[j]);
            }
        }
        return result;
    }
};