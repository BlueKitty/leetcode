class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<int> sorted = candidates;
        sort(sorted.begin(), sorted.end());
        vector<int> solution;
        int sum = 0;
        vector<vector<int> > results;
        stack<pair<int, bool> > dfs_stack;
        for (int candidate : sorted) dfs_stack.push({candidate, false});
        while (!dfs_stack.empty()) {
            while (dfs_stack.top().second == true) {
                dfs_stack.pop();
                sum -= solution.back();
                solution.pop_back();
                if (dfs_stack.empty()) return results;
            }
            auto& num = dfs_stack.top();
            sum += num.first;
            num.second = true; // mark as visited
            solution.push_back(num.first);
            if (sum == target) {
                results.push_back(solution);
            } else if (sum < target) {
                for (auto it = lower_bound(sorted.begin(), sorted.end(), solution.back());
                        it != sorted.end(); ++it) {
                    dfs_stack.push({*it, false});
                }
            }
        }
        return results;
    }
};