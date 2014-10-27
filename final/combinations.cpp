class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        if (k > n || k == 0) return {};
        queue<vector<int> > combination_queue;
        combination_queue.push({});
        while (combination_queue.front().size() < k) {
            vector<int> base = combination_queue.front();
            combination_queue.pop();
            int base_size = base.size();
            int min_next = base.size() ? base.back() + 1 : 1;
            int max_next = n - (k - base_size - 1);
            for (int i = min_next; i <= max_next; ++i) {
                vector<int> new_combination = base;
                new_combination.push_back(i);
                combination_queue.push(new_combination);
            }
        }
        vector<vector<int> > result;
        while (!combination_queue.empty()) {
            result.push_back(combination_queue.front());
            combination_queue.pop();
        }
        return result;
    }
};