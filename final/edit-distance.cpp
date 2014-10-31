class Solution {
public:
    int minDistance(string word1, string word2) {
        if (word1.length() < word2.length()) /* make sure word1 is longer */
            return minDistance(word2, word1);
        /* we only need to keep previous row: O(word2.length()) extra space */
        vector<int> record(word2.length() + 1, 0);
        int upper_left = 0;
        for (int i = 0; i <= word2.length(); ++i) record[i] = i;
        for (int i = 1; i <= word1.size(); ++i) {
            upper_left = record[0]; /* upperleft: dist(word1[0:i-1], word2[0:j-1]) */
            record[0] = i; /* dist(empty, word2[0:i]) */
            for (int j = 1; j <= word2.size(); ++j) {
                int upper = record[j]; /* upper: dist(word1[0,i-1],word2[0:j]) */
                if (word1[i - 1] == word2[j - 1])
                    record[j] = upper_left;
                else
                    record[j] = 1 + min(upper_left, min(record[j], record[j - 1]));
                upper_left = upper;
            }
        }
        return record[word2.length()];
    }
};