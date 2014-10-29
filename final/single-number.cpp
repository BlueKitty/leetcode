class Solution {
public:
    int singleNumber(int A[], int n) {
        int xor_result = 0;
        for (int i = 0; i < n; i++)
            xor_result ^= A[i];
        return xor_result;
    }
};