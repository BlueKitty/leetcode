#define TEST_AND_CONVERT(level) \
        if (num >= level) { \
            result += int_to_str[level]; \
            num -= level; \
        }

class Solution {
public:
    string intToRoman(int num) {
        string result = "";
        unordered_map<int, string> int_to_str = {
            {1, "I"}, {4, "IV"}, {5, "V"}, {9, "IX"}, {10, "X"},
            {40, "XL"}, {50, "L"}, {90, "XC"}, {100, "C"},
            {400, "CD"}, {500, "D"}, {900, "CM"}, {1000, "M"}
        };
        while (num > 0) {
            TEST_AND_CONVERT(1000)
            else TEST_AND_CONVERT(900)
            else TEST_AND_CONVERT(500)
            else TEST_AND_CONVERT(400)
            else TEST_AND_CONVERT(100)
            else TEST_AND_CONVERT(90)
            else TEST_AND_CONVERT(50)
            else TEST_AND_CONVERT(40)
            else TEST_AND_CONVERT(10)
            else TEST_AND_CONVERT(9)
            else TEST_AND_CONVERT(5)
            else TEST_AND_CONVERT(4)
            else TEST_AND_CONVERT(1)
        }
        return result;
    }
};