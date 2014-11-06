class Solution {
public:
    string minWindow(string S, string T) {
        unordered_map<char, int> occurance;
        for (char c : T) {
            if (occurance.count(c) == 0) occurance[c] = 0;
            occurance[c]--;
        }
        int negative_count = occurance.size(), cur_begin = 0, min_begin = 0, min_len = INT_MAX;
        for (int i = 0; i < S.size(); ++i) {
            if (occurance.count(S[i])) {
                if (occurance[S[i]] == -1) negative_count--;
                occurance[S[i]]++;
                while (negative_count == 0) {
                    if (occurance.count(S[cur_begin])) {
                        occurance[S[cur_begin]]--;
                        if (occurance[S[cur_begin]] == -1) negative_count++;
                    }
                    if (min_len > i - cur_begin + 1) {
                        min_len = i - cur_begin + 1;
                        min_begin = cur_begin;
                    }
                    cur_begin++;
                }
            }
        }
        return min_len == INT_MAX ? "" : S.substr(min_begin, min_len);
    }
};