class Solution {
public:
    // from https://github.com/soulmachine/leetcode
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        if (n == 0) return {""};
        if (n == 1) return {"()"};
        for (int i = 0; i < n; i++) {
            for (auto inner : generateParenthesis(i)) {
                for (auto outer : generateParenthesis(n - i - 1)) {
                    result.push_back("(" + inner + ")" + outer);
                }
            }
        }
        return result;
    }
};