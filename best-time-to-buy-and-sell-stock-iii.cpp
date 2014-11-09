/* Idea: since the two transactions are non-overlapping, they are the max-profit ones in 
 * two intervals. Do a forward traversal for maxima by every day and do a backward
 * traversal for maxima since everyday and find the maximum sum. */
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        vector<int> max_by(n, 0);
        int valley = INT_MAX, cur_max_by = 0;
        for (int i = 0; i < n; ++i) {
            valley = min(valley, prices[i]);
            cur_max_by = max(cur_max_by, prices[i] - valley);
            max_by[i] = cur_max_by;
        }
        int peak = INT_MIN, cur_max_since = 0, max_profit = 0;
        for (int i = n - 1; i > 0; --i) {
            peak = max(peak, prices[i]);
            cur_max_since = max(cur_max_since, peak - prices[i]);
            max_profit = max(max_profit, cur_max_since + max_by[i]);
        }
        return max_profit;
    }
};