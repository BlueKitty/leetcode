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
    bool isBalanced(TreeNode *root) {
        return (check_height(root) != -1);
    }
    int check_height(TreeNode *root) {
        if (root == NULL) return 0;
        int left_height = check_height(root->left);
        if (left_height < 0) return -1;
        int right_height = check_height(root->right);
        if (right_height < 0 || abs(left_height - right_height) > 1) {
            return -1;
        }
        return max(left_height, right_height) + 1;
    }
};