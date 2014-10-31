class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        auto v = S;
        sort(v.begin(), v.end());
        vector<vector<int> > result(1);
        int prev_num = INT_MIN, prev_start_idx = 0;
        for (int num : v) {
            int cur_start_idx = result.size();
            for (int i = num == prev_num ? prev_start_idx : 0; i < cur_start_idx; ++i) {
                result.push_back(result[i]);
                result.back().push_back(num);
            }
            prev_start_idx = cur_start_idx;
            prev_num = num;
        }
        return result;
    }
};