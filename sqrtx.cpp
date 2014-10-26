class Solution {
public:
    int sqrt(int x) {
        int res = 1, prev_res = 0;
        while (prev_res != res) {
            prev_res = res;
            res = (x / res + res) / 2;
        }
        return res;
    }
};