class Solution {
private:
    vector<char> stack;
    bool stack_match(char closing) {
        switch (closing) {
            case ')':
                if (stack.back() == '(')
                    return true;
                break;
            case ']':
                if (stack.back() == '[')
                    return true;
                break;
            case '}':
                if (stack.back() == '{')
                    return true;
                break;
        }
        return false;
    }
public:
    bool isValid(string s) {
        for (int i = 0; i < s.size(); i++) {
            switch (s[i]) {
            case '(':
            case '[':
            case '{':
                stack.push_back(s[i]);
                break;
            case ')':
            case ']':
            case '}':
                if (stack.size() == 0 || !stack_match(s[i])) {
                    return false;
                } else {
                    stack.pop_back();
                    break;
                }
            }
        }
        if (stack.size() == 0)
            return true;
        else
            return false;
    }
};