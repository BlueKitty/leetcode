class Solution {
public:
    string convert(string s, int nRows) {
        if (nRows <= 1) return s;
        string result;
        int period = 2 * nRows - 2;
        for (int i = 0; i < nRows; ++i) {
            int second_offset = 2 * (nRows - i - 1);
            for (int j = i; j < s.size(); j += period) {
                result += s[j];
                if (i != 0 && i != nRows - 1 && j + second_offset < s.size())
                    result += s[j + second_offset];
            }
        }
        return result;
    }
};