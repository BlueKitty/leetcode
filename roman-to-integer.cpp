class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        int roman[256] = {0};
        roman['I'] = 1;
        roman['V'] = 5;
        roman['X'] = 10;
        roman['L'] = 50;
        roman['C'] = 100;
        roman['D'] = 500;
        roman['M'] = 1000;
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