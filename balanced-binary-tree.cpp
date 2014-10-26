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
    bool balanced;
    bool isBalanced(TreeNode *root) {
        balanced = true;
        check_height(root);
        return balanced;
    }
    int check_height(TreeNode *root) {
        if (root == NULL) {
            return 0;
        } else {
            if (!balanced) {
                // already detected, no use for further exploration
                return 0;
            }
            int left_height = check_height(root->left);
            int right_height = check_height(root->right);
            if (abs(left_height - right_height) > 1) {
                balanced = false;
            }
            return max(left_height, right_height) + 1;
        }
    }
};