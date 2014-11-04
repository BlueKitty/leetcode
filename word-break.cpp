class Solution {
private:
    unordered_map<string, bool> record;
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        if (dict.count(s)) return true;
        if (record.count(s)) return record[s];
        int n = s.size();
        for (int i = 1; i < n; ++i) {
            if (dict.count(s.substr(0, i)) && wordBreak(s.substr(i, n - i), dict)) {
                record[s] = true;
                return true;
            }
        }
        record[s] = false;
        return false;
    }
};