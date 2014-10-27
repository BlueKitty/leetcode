class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<int> sorted = candidates, solution;
        sort(sorted.begin(), sorted.end());
        int sum = 0, n = sorted.size();
        vector<vector<int> > results;
        stack<pair<int, bool> > dfs_stack;
        for (int i = 0; i < n; ++i) dfs_stack.push({i, false});
        while (!dfs_stack.empty()) {
            auto& idx_pair = dfs_stack.top();
            sum += sorted[idx_pair.first];
            idx_pair.second = true; // mark as visited
            solution.push_back(sorted[idx_pair.first]);
            if (sum == target) {
                results.push_back(solution);
            } else if (sum < target) {
                for (int i = idx_pair.first; i < n; ++i) dfs_stack.push({i, false});
            }
            while (!dfs_stack.empty() && dfs_stack.top().second == true) {
                sum -= solution.back();
                dfs_stack.pop();
                solution.pop_back();
            }
        }
        return results;
    }
};