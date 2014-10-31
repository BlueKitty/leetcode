class Solution {
public:
    void reverseWords(string &s) {
        string result;
        for (auto it = s.rbegin(); it != s.rend(); ) {
            while (it != s.rend() && *it == ' ') it++;
            string word = "";
            while (it != s.rend() && *it != ' ') word.push_back(*(it++));
            if (word.size() == 0) break;
            reverse(word.begin(), word.end());
            if (result.size() > 0) result += ' '; 
            result.append(word);
        }
        s = result;
    }
};