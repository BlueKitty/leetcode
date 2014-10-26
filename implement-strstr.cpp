class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        if (!haystack || !needle || needle[0] == '\0') return haystack;
        int i = 0, j = 0;
        for (int i = 0; haystack[i] != '\0'; ++i) {
            bool matched = true;
            for (int j = 0; needle[j] != '\0'; ++j) {
                if (needle[j] != haystack[i + j]) {
                    if (haystack[i + j] == '\0') return NULL;
                    matched = false;
                    break;
                }
            }
            if (matched) return &(haystack[i]);
        };
        return NULL;
    }
};