/* Solution from 
 * http://fisherlei.blogspot.com/2013/04/leetcode-permutation-sequence-solution.html */
class Solution {
public:
    string getPermutation(int n, int k) {
        string result;
        int permutation_count = 1;
        string digits(n, 0);
        for (int i = 1; i <= n; ++i) {
            digits[i - 1] = i + '0';
            permutation_count *= i;
        }
        k--;
        for (int i = n; i >= 1; --i) {
            permutation_count /= i;
            /* permutation_count = (i - 1)!, which is num of permutations for last (i - 1)
             * digits */
            int idx = k / permutation_count;
            result.push_back(digits[idx]);
            digits.erase(digits.begin() + idx);
            k %= permutation_count;
        }
        return result;
    }
};