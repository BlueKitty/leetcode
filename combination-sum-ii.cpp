class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        vector<vector<int> > results;
        vector<int> v = num;
        sort(v.begin(), v.end());
        stack<int> dfs_stack;
        vector<bool> visited(v.size(), false);
        for (int i = 0; i < v.size(); ++i) {
            dfs_stack.push(i);
            while (i + 1 < v.size() && v[i] == v[i + 1]) ++i;
        }
        vector<int> solution;
        int sum = 0;
        while (!dfs_stack.empty()) {
            int idx = dfs_stack.top();
            while (visited[idx]) {
                solution.pop_back();
                visited[idx] = false;
                sum -= v[idx];
                dfs_stack.pop();
                if (!dfs_stack.empty())
                    idx = dfs_stack.top();
                else
                    return results;
            }
            int val = v[idx];
            visited[idx] = true;
            sum += val;
            solution.push_back(val);
            if (sum == target) {
                results.push_back(solution);
            } else if (sum < target) {
                for (int i = idx + 1; i < v.size(); ++i) {
                    dfs_stack.push(i);
                    while (i + 1 < v.size() && v[i] == v[i + 1]) ++i;
                }
            }
        }
        return results;
    }
};