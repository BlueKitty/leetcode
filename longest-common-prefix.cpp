class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.size() == 0)
            return "";
        string prefix = "";
        for (int i = 0; i < strs[0].size(); i++) {
            char candidate = strs[0][i];
            for (int j = 1; j < strs.size(); j++) {
                // checking the candidate character
                if (strs[j].size() <= i || strs[j][i] != candidate) {
                    return prefix;
                }
            }
            prefix += candidate;
        }
        return prefix;
    }
};