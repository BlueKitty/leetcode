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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;
        if (root == NULL)
            return result;
        vector<int> left_vector = inorderTraversal(root->left);
        vector<int> right_vector = inorderTraversal(root->right);
        result.reserve(left_vector.size() + right_vector.size() + 1);
        result.insert(result.end(), left_vector.begin(), left_vector.end());
        result.push_back(root->val);
        result.insert(result.end(), right_vector.begin(), right_vector.end());
    }
};