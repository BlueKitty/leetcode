class Solution {
public:
    bool isNumber(const char *s) {
        while (*s == ' ') ++s;
        if (*s == '+' || *s == '-') ++s;
        bool decimal_point_allowed = true, e_allowed = true, digit_detected = false;
        while (*s != '\0' && *s != ' ') {
            if (isdigit(*s)) {
                digit_detected = true;
            } else if (*s == 'e' && e_allowed && digit_detected) {
                if (*(s + 1) == '+' || *(s + 1) == '-') ++s;
                digit_detected = false;
                e_allowed = false;
                decimal_point_allowed = false;
            } else if (*s == '.' && decimal_point_allowed) {
                decimal_point_allowed = false;
            } else {
                return false;
            }
            ++s;
        }
        while (*s == ' ') ++s;
        return (digit_detected && *s == '\0');
    }
};