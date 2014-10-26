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
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > result;
        if (root == NULL) {
            return result;
        }
        list<TreeNode *> current_level, next_level;
        current_level.push_back(root);
        bool stop = false;
        while (!stop) {
            vector<int> level_result;
            while (!current_level.empty()) {
                TreeNode *node = current_level.front();
                current_level.pop_front();
                level_result.push_back(node->val);
                if (node->left != NULL) {
                    next_level.push_back(node->left);
                }
                if (node->right != NULL) {
                    next_level.push_back(node->right);
                }
            }
            result.push_back(level_result);
            if (next_level.empty()) {
                stop = true;
            } else {
                current_level = next_level;
                next_level.clear();
            }
        }
        return result;
    }
};