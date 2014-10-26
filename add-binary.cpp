class Solution {
public:
    string addBinary(string a, string b) {
        string result;
        int carry = 0;
        for (int i = 1; i <= a.size() || i <= b.size(); ++i) {
            char a_digit = i <= a.size() ? *(a.end() - i) - '0' : 0;
            char b_digit = i <= b.size() ? *(b.end() - i) - '0' : 0;
            char partial_result = a_digit + b_digit + carry;
            char result_digit = partial_result % 2;
            carry = partial_result >> 1;
            result.push_back(result_digit + '0');
        }
        if (carry) result.push_back(carry + '0');
        reverse(result.begin(), result.end());
        return result;
    }
};