/* This is the clean version by Pumbaa */
/* Question: It is faster than the appending version. Is that because of locality? */
class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.size() == 0)
            return "";
        string prefix = strs[0];
        for (auto& str : strs) {
            int i = 0;
            while (i < prefix.size() && i < str.size() && str[i] == prefix[i]) ++i;
            prefix = prefix.substr(0, i);
        }
        return prefix;
    }
};

/* Original appending version */
class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.size() == 0)
            return "";
        string prefix = "";
        for (int i = 0; i < strs[0].size(); ++i) {
            for (auto &str : strs) {
            	if (i == str.size() || str[i] != strs[0][i]) return prefix;
            }
            prefix += strs[0][i];
        }
        return prefix;
    }
};