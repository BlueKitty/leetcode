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
    void find_min_depth(TreeNode *root, int depth, int &current_min) {
        if (depth >= current_min || root == NULL) return;
        if (root->left == NULL && root->right == NULL) {
            current_min = min(current_min, depth + 1);
        } else {
            find_min_depth(root->left, depth + 1, current_min);
            find_min_depth(root->right, depth + 1, current_min);
        }
    }
    int minDepth(TreeNode *root) {
        if (root == NULL) return 0;
        int current_min_depth = INT_MAX;
        find_min_depth(root, 0, current_min_depth);
        return current_min_depth;
    }
};