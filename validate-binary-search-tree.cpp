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
    int last_num = INT_MIN; // last visited number for inorder traversal
    bool isValidBST(TreeNode *root) {
        if (root == NULL) return true;
        if (!isValidBST(root->left)) return false;
        if (root->val <= last_num) return false;
        last_num = root->val;
        if (!isValidBST(root->right)) return false;
        return true;
    }
};