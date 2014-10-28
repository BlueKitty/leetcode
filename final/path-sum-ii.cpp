/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void check_path(TreeNode *root, vector<int> &path_vector, int sum, int target,
                    vector<vector<int> > &result) {
        if (root == NULL) return;
        int path_sum = sum + root->val;
        path_vector.push_back(root->val);
        if (root->left == NULL && root->right == NULL) {
            if (path_sum == target) result.push_back(path_vector);
        } else {
            check_path(root->left, path_vector, path_sum, target, result);
            check_path(root->right, path_vector, path_sum, target, result);
        }
        path_vector.pop_back();
    }
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > result;
        vector<int> path_vector;
        check_path(root, path_vector, 0, sum, result);
        return result;
    }
};

class Solution {
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        if (!root) return {};
        stack<pair<TreeNode *, bool> > dfs_stack;
        int cur_sum = 0;
        vector<vector<int> > result;
        vector<int> cur_path;
        dfs_stack.push({root, false});
        while (!dfs_stack.empty()) {
            pair<TreeNode *, bool> &node = dfs_stack.top();
            TreeNode *cur_node = node.first;
            if (!node.second) { // not visited
                node.second = true;
                cur_sum += cur_node->val;
                cur_path.push_back(cur_node->val);
                if (!cur_node->left && !cur_node->right && cur_sum == sum) {
                    result.push_back(cur_path);
                }
                if (cur_node->left) dfs_stack.push({cur_node->left, false});
                if (cur_node->right) dfs_stack.push({cur_node->right, false});
            } else { //backtrack
                cur_sum -= cur_node->val;
                cur_path.pop_back();
                dfs_stack.pop();
            }
        }
        return result;
    }
};