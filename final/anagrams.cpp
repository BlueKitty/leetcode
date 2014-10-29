class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        unordered_map<string, vector<string> > record;
        for(int i = 0; i< strs.size(); i++) {
            string sorted = strs[i];
            sort(sorted.begin(), sorted.end());
            if (!record.count(sorted))
                record.insert(pair<string, vector<string> >(sorted, {}));
            record.find(sorted)->second.push_back(strs[i]);
        }
        vector<string> results;
        for (auto it = record.begin(); it != record.end(); it++) {
            if (it->second.size() > 1) {
                for (auto anagram : it->second) results.push_back(anagram);
            }
        }
        return results;
    }
};