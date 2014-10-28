/* Iterative solution */
class Solution {
public:
    double pow(double x, int n) {
        if (n == 0) return 1;
        double result = 1;
        x = n > 0 ? x : 1 / x;
        for (n = abs(n); n > 0; n /= 2) {
            if (n % 2 == 1) result *= x;
            x *= x;
        }
        return result;
    }
};

/* Recursive solution */
class Solution {
public:
    double pow(double x, int n) {
        if (n == 0) return 1;
        double half = pow(x, n/2);
        if (n % 2 == 0) {
            return half * half;
        } else {
            if (n > 0) {
                return half * half * x;
            } else {
                return half * half / x;
            }
        }
    }
};