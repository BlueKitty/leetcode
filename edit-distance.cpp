class Solution {
public:
    int minDistance(string word1, string word2) {
        if (word1.length() < word2.length())
            return minDistance(word2, word1);
        vector<int> f(word2.length() + 1, 0);
        int upper_left = 0;
        for (int i = 0; i <= word2.length(); ++i) f[i] = i;
        for (int i = 1; i <= word1.size(); ++i) {
            upper_left = f[0];
            f[0] = i;
            for (int j = 1; j <= word2.size(); ++j) {
                int upper = f[j];
                if (word1[i - 1] == word2[j - 1])
                    f[j] = upper_left;
                else
                    f[j] = 1 + min(upper_left, min(f[j], f[j - 1]));
                upper_left = upper;
            }
        }
        return f[word2.length()];
    }
};