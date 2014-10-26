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
    // return the last non-null node after flatten
    TreeNode *flatten_helper(TreeNode *root) {
        if (root == NULL) {
            return NULL;
        }
        TreeNode *original_left = root->left;
        TreeNode *original_right = root->right;
        if (original_left != NULL) {
            root->right = original_left;
            root->left = NULL;
        }
        TreeNode *left_end = flatten_helper(original_left);
        if (left_end != NULL) {
            left_end->right = original_right;
        } else {
            root->right = original_right;
        }
        TreeNode *right_end = flatten_helper(original_right);
        if (right_end == NULL) {
            if (left_end == NULL) {
                return root;
            } else {
                return left_end;
            }
        } else {
            return right_end;
        }
    }
    void flatten(TreeNode *root) {
        flatten_helper(root);
    }
};