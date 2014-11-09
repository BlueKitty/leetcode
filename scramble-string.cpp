class Solution {
    unordered_map<string, unordered_map<string, bool>> record;
public:
    bool isScramble(string s1, string s2) {
        if (s1 == s2) return true;
        int n = s1.size();
        if (record.count(s1) && record[s1].count(s2)) return record[s1][s2];
        for (int i = 1; i < n; ++i) {
            if ((isScramble(s1.substr(0, i), s2.substr(0, i)) &&
                    isScramble(s1.substr(i, n - i), s2.substr(i, n - i))) ||
                (isScramble(s1.substr(0, i), s2.substr(n - i, i)) &&
                    isScramble(s1.substr(i, n - i), s2.substr(0, n - i)))) {
                record[s1][s2] = true;
                return true;
            }
        }
        record[s1][s2] = false;
        return false;
    }
};