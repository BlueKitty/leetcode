/* Similar as Pumbaa's solution but avoid using recursion */
class Solution {
public:
    string intToRoman(int num) {
        vector<int> numbers = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> numerals = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
        string result = "";
        int i = 0;
        while (num > 0) {
            if (numbers[i] > num) {
                i++;
            } else {
                result += numerals[i];
                num -= numbers[i];
            } 
        }
        return result;
    }
};