class Solution {
public:
    string longestPalindrome(string s) {
        int begin = 0, max_len = 0, n = s.size();
        for (int i = 0; i < n; ++i) {
            int j;
            for (j = 1; i - j >=0 && i + j < n && s[i - j] == s[i + j]; ++j) {}
            j--;
            if (2 * j + 1 > max_len) {
                begin = i - j;
                max_len = 2 * j + 1;
            }
            for (j = 1; i - j + 1 >= 0 && i + j < n && s[i - j + 1] == s[i + j]; ++j) {}
            j--;
            if (2 * j > max_len) {
                begin = i - j + 1;
                max_len = 2 * j;
            }
        }
        return s.substr(begin, max_len);
    }
};