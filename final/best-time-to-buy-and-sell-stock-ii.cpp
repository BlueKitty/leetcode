class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int prev_price = INT_MAX, profit = 0;
        for (int price : prices) {
            if (price > prev_price) profit += price - prev_price;
            prev_price = price;
        }
        return profit;
    }
};