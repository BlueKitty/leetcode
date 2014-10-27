class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> keyboard = {" ", "", // 0 , 1
            "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}; // 2 - 9
        vector<string> result = { "" };
        for (auto digit : digits) {
            int n = result.size();
            string letters = keyboard[digit - '0'];
            for (int i = 1; i < letters.size(); ++i) {
                for (int j = 0; j < n; ++j) {
                    result.push_back(result[j] + letters[i]);
                }
            }
            for (int j = 0; j < n; ++j) result[j] += letters[0];
        }
        return result;
    }
};