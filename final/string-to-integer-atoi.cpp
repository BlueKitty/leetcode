class Solution {
public:
    int atoi(const char *str) {
        int i = 0, sign = 1;
        while (isspace(str[i])) i++;
        if (str[i] == '-') {
            sign = -1;
            i++;
        } else if (str[i] == '+') {
            i++;
        }
        long long result = 0;
        while (isdigit(str[i])) {
            result = result * 10 + (str[i] - '0');
            if (result > INT_MAX) return sign > 0 ? INT_MAX : INT_MIN;
            i++;
        }
        return (int)(result * sign);
    }
};