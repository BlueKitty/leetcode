class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        unordered_map<char, int> roman = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
                                          {'C', 100}, {'D', 500}, {'M', 1000}};
        int last_int = INT_MIN;
        for (int i = s.size() - 1; i >= 0; --i) {
            int current_int = roman[s[i]];
            if (current_int < last_int) {
                result -= current_int;
            } else {
                result += current_int;
            }
            last_int = current_int;
        }
        return result;
    }
};