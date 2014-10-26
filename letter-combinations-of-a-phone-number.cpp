class Solution {
public:
    vector<string> combination_recursive(string::iterator begin,
                                         string::iterator end,
                                         vector<string> &keyboard) {
        if (begin == end) return { "" };
        char last_num = *(end - 1);
        vector<string> results;
        for (auto combination : combination_recursive(begin, end - 1, keyboard)) {
            for (auto last_char : keyboard[last_num - '0']) {
                results.push_back(combination + last_char);
            }
        }
        return results;
    }
    vector<string> letterCombinations(string digits) {
        vector<string> keyboard = {" ", "", // 0 , 1
            "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}; // 2 - 9
        return combination_recursive(digits.begin(), digits.end(), keyboard);
    }
};