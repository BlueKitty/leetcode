class Solution {
public:
    int candy(vector<int> &ratings) {
        int n = ratings.size(), min_total = 0;
        vector<int> num_candies(n, 1);
        for (int i = 1; i < n; ++i) {
            if (ratings[i] > ratings[i - 1])
                num_candies[i] = num_candies[i - 1] + 1;
        }
        for (int i = n - 1; i >= 1; --i) {
            if (ratings[i - 1] > ratings[i] && num_candies[i - 1] <= num_candies[i])
                num_candies[i - 1] = num_candies[i] + 1;
        }
        for (int num : num_candies) min_total += num;
        return min_total;
    }
};