class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.size(), n = num2.size();
        string result(n + m, '0');
        int carry = 0, partial_result = 0;
        for (int i = 0; i < m; ++i) {
            int j;
            for (j = 0, carry = 0; j < n; ++j) {
                partial_result = (num1[m - 1 - i] - '0') * (num2[n - 1 - j] - '0');
                partial_result += carry + (result[i + j] - '0');
                carry = partial_result / 10;
                result[i + j] = partial_result % 10 + '0';
            }
            result[i + n] += carry;
        }
        while (result.back() == '0' && result.size() > 1) result.pop_back();
        reverse(result.begin(), result.end());
        return result;
    }
};