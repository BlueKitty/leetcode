class Solution {
public:
    int numDecodings(string s) {
        if (s.size() == 0) {
            return 0;
        }
        int n = s.size();
        vector<int> count(n + 1, 0);
        count[0] = 1;
        for (int i = 0; i < n; i++) {
            if (i > 0 && (s[i-1] == '1' || 
                (s[i-1] == '2' && s[i] - '0' >= 0 && s[i] - '0' <= 6))) {
                // '1x' or '20' - '26'
                count[i+1] += count[i-1];
            }
            if (s[i] != '0') {
                count[i+1] += count[i];
            }
        }
        return count[n];
    }
};