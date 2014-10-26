class Solution {
public:
    int numTrees(int n) {
        vector<int> num_tree_vector(n + 1, 0);
        num_tree_vector[0] = 1;
        num_tree_vector[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                num_tree_vector[i] += num_tree_vector[j-1] * num_tree_vector[i-j];
            }
        }
        return num_tree_vector[n];
    }
};