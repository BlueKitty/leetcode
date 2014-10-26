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
    bool hasPathSum(TreeNode *root, int sum) {
        if (root == NULL) return false;
        return testPath(root, 0, sum);
    }
    bool testPath(TreeNode *root, int acc, int sum) {
        if (root->left == NULL && root->right == NULL) {
            // is leaf node
            if (acc + root->val == sum)
                return true;
            else
                return false;
        } else {
            // not leaf node
            if (root->left != NULL && testPath(root->left, acc + root->val, sum)) {
                return true;
            } else if (root->right != NULL && testPath(root->right, acc + root->val, sum)) {
                return true;
            } else {
                return false;
            }
        }
    }
};