class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<int> sorted = num;
        sort(sorted.begin(), sorted.end());
        vector<vector<int> > result;
        int n = sorted.size();
        int i = 0;
        while (i < n) {
            int j = i + 1, k = n - 1;
            while (j < k) {
                int sum = sorted[i] + sorted[j] + sorted[k];
                if (sum < 0) {
                    do {++j;} while (j < n && sorted[j] == sorted[j - 1]);
                } else if (sum > 0) {
                    do {--k;} while (k > i && sorted[k] == sorted[k + 1]);
                } else {
                    result.push_back({sorted[i], sorted[j], sorted[k]});
                    do {++j;} while (j < n && sorted[j] == sorted[j - 1]);
                    do {--k;} while (k > i && sorted[k] == sorted[k + 1]);
                }
            }
            do {++i;} while (i < n && sorted[i] == sorted[i - 1]);
        }
        return result;
    }
};