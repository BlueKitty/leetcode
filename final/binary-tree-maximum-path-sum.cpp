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
    void maxPath(TreeNode *root, int &max_ends_here, int &max_overall) {
        if (root == NULL) {
            max_ends_here = INT_MIN;
            max_overall = INT_MIN;
            return;
        }
        int l_max_half, r_max_half, l_max_overall, r_max_overall;
        maxPath(root->left, l_max_half, l_max_overall);
        maxPath(root->right, r_max_half, r_max_overall);
        max_ends_here = max(0, max(l_max_half, r_max_half)) + root->val;
        int max_through_here = max(0, l_max_half) + max(0, r_max_half) + root->val;
        max_overall = max(max_through_here, max(l_max_overall, r_max_overall));
    }
    int maxPathSum(TreeNode *root) {
        int max_overall, max_ends_here;
        maxPath(root, max_ends_here, max_overall);
        return max_overall;
    }
};