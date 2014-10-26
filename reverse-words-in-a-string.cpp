class Solution {
public:
    void reverseWords(string &s) {
        stack<string> str_stack;
        int i = 0;
        while (i < s.size()) {
            while (s[i] == ' ' && i < s.size()) i++;
            int start = i;
            while (s[i] != ' ' && i < s.size()) i++;
            str_stack.push(s.substr(start, i - start));
        }
        s = "";
        while (!str_stack.empty()) {
            string word = str_stack.top();
            str_stack.pop();
            if (s.size() > 0) s += ' ';
            s += word;
        }
    }
};