/* DP with constant space */
class Solution {
public:
    int numDecodings(string s) {
        if (s.size() == 0) return 0;
        int n = s.size(), prev_ways = 1, prev_prev_ways = 1, ways = 0;
        for (int i = 0; i < n; i++) {
            ways = 0;
            if ((i > 0 && s[i-1] == '1') ||
                (i > 0 && s[i-1] == '2' && s[i] - '0' >= 0 && s[i] - '0' <= 6)) {
                // '1x' or '20' - '26'
                ways += prev_prev_ways;
            }
            if (s[i] != '0')
                ways += prev_ways;
            prev_prev_ways = prev_ways;
            prev_ways = ways;
        }
        return ways;
    }
};