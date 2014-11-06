class Solution {
    unordered_map<string, vector<string>> record;
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        if (record.count(s)) return record[s];
        vector<string> result;
        for (int i = 1; i <= s.size(); ++i) {
            if (dict.count(s.substr(0, i))) {
                if (i == s.size()) {
                    result.push_back(s);
                } else {
                    for (auto &sentence : wordBreak(s.substr(i), dict))
                        result.push_back(s.substr(0, i) + " " + sentence);
                }
            }
        }
        record[s] = result;
        return result;
    }
};