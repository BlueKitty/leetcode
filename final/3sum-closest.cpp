class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        vector<int> v = num;
        sort(v.begin(), v.end());
        int n = v.size();
        int closest_sum = 0, closest_diff = INT_MAX;
        for (int i = 0; i < n - 2; ++i) {
            int j = i + 1, k = n - 1;
            while (j < k) {
                int sum = v[i] + v[j] + v[k];
                int diff = abs(target - sum);
                if (diff == 0) return sum;
                if (diff < closest_diff) {
                    closest_diff = abs(sum - target);
                    closest_sum = sum;
                }
                sum < target ? j++ : k--;
            }
        }
        return closest_sum;
    }
};