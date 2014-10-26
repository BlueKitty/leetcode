class Solution {
public:
    void nextPermutation(vector<int> &num) {
        if (num.empty()) return;
        auto swap1 = num.rbegin() + 1;
        while (swap1 != num.rend() && (*swap1 >= *(swap1 - 1))) swap1++;
        if (swap1 == num.rend()) {
            // last permutation
            sort(num.begin(), num.end());
            return;
        }
        auto swap2 = find_if(num.rbegin(), swap1, bind2nd(greater<int>(), *swap1));
        swap(*swap1, *swap2);
        reverse(num.rbegin(), swap1);
        return;
    }
};