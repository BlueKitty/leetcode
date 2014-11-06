class Solution {
public:
    int longestValidParentheses(string s) {
        int longest_strike = 0;
        int current_strike = 0;
        stack<int> stk;
        for (int i = 0; i < s.size(); ++i) {
            char ch = s[i];
            if (ch == '(') {
                stk.push(i);
            } else if (ch == ')') {
                if (!stk.empty() && s[stk.top()] == '(') {
                    stk.pop();
                    current_strike = i - (stk.empty() ? -1 : stk.top());
                    longest_strike = max(longest_strike, current_strike);
                } else {
                    stk.push(i);
                }
            }
        }
        return longest_strike;
    }
};