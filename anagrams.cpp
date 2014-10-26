class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        map<string, vector<string> > record;
        map<string, vector<string> >::iterator it;
        for(int i = 0; i< strs.size(); i++) {
            string sorted = strs[i];
            sort(sorted.begin(), sorted.end());
            if (record.find(sorted) == record.end()) {
                // not found
                vector<string> str_set;
                record.insert(pair<string, vector<string> >(sorted, str_set));
            }
            it = record.find(sorted);
            it->second.push_back(strs[i]);
        }
        vector<string> results;
        for (it = record.begin(); it != record.end(); it++) {
            if (it->second.size() > 1) {
                for (int i = 0; i < it->second.size(); i++) {
                    results.push_back(it->second[i]);
                }
            }
        }
        return results;
    }
};