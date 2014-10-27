class Solution {
public:
    bool isPalindrome(int x) {
        // reversed int might overflow!!!
        // negative number is impossible
        if (x < 0) return false;
        int divisor = 1;
        while (x / divisor >= 10) divisor *= 10;
        while(x > 0) {
            int first_digit = x / divisor;
            int last_digit = x % 10;
            if (first_digit != last_digit) return false;
            x = x % divisor / 10;
            divisor /= 100;
        }
        return true;
    }
};