class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> last_appearance;
        int max_len = 0, start = -1, n = s.size();
        for (int i = 0; i < n; ++i) {
            char ch = s[i];
            if (last_appearance.count(ch) && last_appearance[ch] > start)
                start = last_appearance[ch];
            else
                max_len = max(max_len, i - start);
            last_appearance[ch] = i;
        }
        return max_len;
    }
};