class Solution {
public:
    int reverse(int x) {
        int sign = x > 0 ? 1 : -1, result = 0;
        x = abs(x);
        while (x > 0) {
            int digit = x % 10;
            x /= 10;
            result *= 10;
            result += digit;
        }
        return result * sign;
    }
};