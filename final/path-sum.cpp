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
    bool check_path(TreeNode *root, int cur_sum, int target) {
        if (!root) return false;
        cur_sum += root->val;
        if (!root->left && !root->right) return cur_sum == target;
        return (check_path(root->left, cur_sum, target)
                || check_path(root->right, cur_sum, target));
    }
    bool hasPathSum(TreeNode *root, int sum) {
        return check_path(root, 0, sum);
    }
};

class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if (!root) return false;
        stack<pair<TreeNode *, bool> > dfs_stack;
        int cur_sum = 0;
        dfs_stack.push({root, false});
        while (!dfs_stack.empty()) {
            pair<TreeNode *, bool> &node = dfs_stack.top();
            if (!node.second) { // not visited
                node.second = true;
                cur_sum += node.first->val;
                if (!node.first->left && !node.first->right && cur_sum == sum) {
                    return true;
                }
                if (node.first->left) dfs_stack.push({node.first->left, false});
                if (node.first->right) dfs_stack.push({node.first->right, false});
            } else { //backtrack
                cur_sum -= node.first->val;
                dfs_stack.pop();
            }
        }
        return false;
    }
};