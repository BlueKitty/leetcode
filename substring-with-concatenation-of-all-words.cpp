class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        int word_count = L.size(), n = S.size();
        if (L.size() == 0) return {};
        unordered_map<string, int> original_quota, cur_quota;
        for (auto &str : L) { /* Note: there can be duplicates in L !! */
            if (!original_quota.count(str)) original_quota[str] = 0;
            original_quota[str]++;
        }
        int word_len = L[0].size(), matched_count = 0;
        vector<int> result;
        for (int i = 0; i < word_len; ++i) {
            cur_quota = original_quota;
            matched_count = 0;
            for (int j = i; j <= n - word_len;) {
                string word = S.substr(j, word_len);
                if (cur_quota.count(word)) {
                    if (cur_quota[word] > 0) { /* can be matched */
                        cur_quota[word]--;
                        matched_count++;
                        j += word_len;
                        if (matched_count == word_count)
                            result.push_back(j - word_count * word_len);
                    } else if (cur_quota[word] == 0) {
                    	/* can be matched but no enough quota, release from beginning and
                    	   try again in next iteration */
                        int start_index = j - matched_count * word_len;
                        cur_quota[S.substr(start_index, word_len)]++;
                        matched_count--;
                    }
                } else {
                	/* the word is not in dictionary, fast forward to next position */
                    for (int i = j - matched_count * word_len; i < j; i += word_len) {
                        cur_quota[S.substr(i, word_len)]++;
                        matched_count--;
                    }
                    j += word_len;
                }
            }
        }
        return result;
    }
};