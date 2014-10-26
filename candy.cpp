class Solution {
public:
    int candy(vector<int> &ratings) {
        int n = ratings.size();
        vector<int> from_left(n, 1);
        vector<int> from_right(n, 1);
        for (int i = 1; i < n; ++i) {
            if (ratings[i] > ratings[i - 1])
                from_left[i] = from_left[i - 1] + 1;
            if (ratings[n - i - 1] > ratings[n - i])
                from_right[n - i - 1] = from_right[n - i] + 1;
        }
        int min_candies = 0;
        for (int i = 0; i < n; ++i) min_candies += max(from_left[i], from_right[i]);
        return min_candies;
    }
};