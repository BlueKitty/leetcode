class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> closing = { {'[', ']'}, {'(', ')'}, {'{', '}'} };
        stack<char> par_stack;
        for (char c : s) {
            if (closing.count(c)) { // opening brackets
                par_stack.push(c);
            } else {
                if (par_stack.empty() || closing[par_stack.top()] != c) return false;
                par_stack.pop(); // matched
            }
        }
        return par_stack.empty();
    }
};