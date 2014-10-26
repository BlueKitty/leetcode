class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<int> v = num;
        sort(v.begin(), v.end());
        int n = v.size();
        vector<vector<int> > result;
        stack<int> dfs_stack;
        for (int i = 0; i < n; i++) {
            dfs_stack.push(i);
            while (i + 1 < n && v[i] == v[i + 1]) ++i;
        }
        vector<bool> visited(n, false);
        vector<int> permutation;
        while (!dfs_stack.empty()) {
            int idx = dfs_stack.top();
            while (visited[idx]) {
                permutation.pop_back();
                dfs_stack.pop();
                visited[idx] = false;
                if (dfs_stack.empty()) return result;
                else idx = dfs_stack.top();
            }
            permutation.push_back(v[idx]);
            visited[idx] = true;
            if (permutation.size() == n) {
                result.push_back(permutation);
            } else {
                for (int i = 0; i < n; i++) {
                    if (visited[i]) continue;
                    dfs_stack.push(i);
                    while (i + 1 < n && v[i] == v[i + 1]) ++i;
                }
            }
        }
        return result;
    }
};