class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        vector<int> result = digits;
        int i = digits.size() - 1; // the last digit
        while (i >= 0) {
            if (result[i] < 9) {
                result[i] += 1;
                break;
            } else if (result[i] == 9){
                result[i] = 0;
            }
            i--;
        }
        if (i < 0) {
            result.insert(result.begin(), 1);
        }
        return result;
    }
};