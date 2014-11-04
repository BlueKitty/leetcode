class Solution {
public:
    int divide(int dividend, int divisor) {
        int sign = 1;
        if ((dividend < 0 && divisor > 0) ||
            (dividend > 0 && divisor < 0)) sign = -1;
        long long dividend_64bit = abs((long long)dividend);
        long long divisor_64bit = abs((long long)divisor);
        long long subtractor = divisor_64bit, divisor_multiple = 1, result = 0;
        while (dividend_64bit >= divisor_64bit) {
            dividend_64bit -= subtractor;
            result += divisor_multiple;
            subtractor <<= 1;
            divisor_multiple <<= 1;
            while (subtractor > dividend_64bit) {
                subtractor >>= 1;
                divisor_multiple >>= 1;
            }
        }
        return sign > 0 ? result : -result;
    }
};