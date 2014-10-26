class Solution {
public:
    int maxSubArray(int A[], int n) {
        if (n <= 0) return 0;
        vector<int> record(n);
        record[0] = A[0];
        int max_value = record[0];
        for (int i = 1; i < n; i++) {
            record[i] = max(record[i - 1] + A[i], A[i]);
            if (record[i] > max_value)
                max_value = record[i];
        }
        return max_value;
    }
};