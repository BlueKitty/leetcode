class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        vector<int> result = digits;
        int carry = 1;
        for (int i = digits.size() - 1; i >= 0; --i) {
            result[i] += carry;
            carry = result[i] / 10;
            if (!carry) break;
            result[i] %= 10;
        }
        if (carry) result.insert(result.begin(), 1);
        return result;
    }
};