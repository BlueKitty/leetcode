/* TODO: use DP for optimization */
class Solution {
public:
    bool is_palindrome(string &s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (s[i++] != s[j--]) return false;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        int n = s.size();
        if (n == 0) return { {} };
        vector<vector<string>> result;
        for (int i = 1; i <= n; ++i) {
            string last_substr = s.substr(n - i);
            if (is_palindrome(last_substr)) {
                for (auto &partial_partition : partition(s.substr(0, n - i))) {
                    partial_partition.push_back(last_substr);
                    result.push_back(partial_partition);
                }
            }
        }
        return result;
    }
};