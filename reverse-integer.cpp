class Solution {
public:
    int reverse(int x) {
        int res = 0;
        int abs_val = x > 0 ? x : -x;
        while (abs_val > 0) {
            int digit = abs_val % 10;
            abs_val /= 10;
            res *= 10;
            res += digit;
        }
        res = x > 0 ? res : -res;
        return res;
    }
};