/* A clean solution */
class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        int n = strlen(haystack), m = strlen(needle);
        if (m == 0) return haystack;
        for (int i = 0; i < n - m + 1; ++i) {
            int j;
            for (j = 0; j < m; ++j) {
                if (haystack[i + j] != needle[j]) break;
            }
            if (j == m) return haystack + i;
        }
        return NULL;
    }
};

/* A faster solution without doing strlen */
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
            if (matched) return haystack + i;
        }
    }
};