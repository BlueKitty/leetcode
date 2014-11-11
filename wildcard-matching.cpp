/* Solution from http://yucoding.blogspot.com/2013/02/leetcode-question-123-wildcard-matching.html */
class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        const char *last_star = NULL, *first_input_not_matching_star = NULL;
        while (*s) {
            if (*p == '?' || *s == *p) {
                ++s;
                ++p;
            } else if (*p == '*') {
                last_star = p++;
                first_input_not_matching_star = s;
            } else if (last_star) {
                p = last_star + 1;
                s = ++first_input_not_matching_star;
            } else {
                return false;
            }
        }
        while (*p == '*') ++p;
        return *p == '\0';
    }
};