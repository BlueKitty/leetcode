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
    bool isSymmetric(TreeNode *root) {
        if (root == NULL)
            return true;
        vector<TreeNode *> left_stack, right_stack;
        left_stack.push_back(root->left);
        right_stack.push_back(root->right);
        while (!left_stack.empty() && !right_stack.empty()) {
            // both are not explored completely, keep matching;
            TreeNode *left_node = left_stack.back();
            left_stack.pop_back();
            TreeNode *right_node = right_stack.back();
            right_stack.pop_back();
            if (!left_node && !right_node) {
                continue;
            } else if ((left_node && !right_node) ||
                       (!left_node && right_node)) {
                return false;
            } else {
                if (left_node->val != right_node->val) {
                    return false;
                } else {
                    left_stack.push_back(left_node->left);
                    left_stack.push_back(left_node->right);
                    right_stack.push_back(right_node->right);
                    right_stack.push_back(right_node->left);
                }
            }
        }
        if (left_stack.empty() && right_stack.empty()) {
            return true;
        } else {
            return false;
        }
    }
};