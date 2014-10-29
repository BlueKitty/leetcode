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
    TreeNode *copyTree(TreeNode *root) {
        if (root == NULL) return NULL;
        TreeNode *new_root = new TreeNode(root->val);
        TreeNode *left_subtree = copyTree(root->left);
        TreeNode *right_subtree = copyTree(root->right);
        new_root->left = left_subtree;
        new_root->right = right_subtree;
        return new_root;
    }
    void eraseTree(TreeNode *root) {
        if (root == NULL) return;
        eraseTree(root->left);
        eraseTree(root->right);
        delete root;
        return;
    }
    vector<TreeNode *> generateTrees(int n) {
        if (n == 0) return { NULL };
        if (n == 1) return { new TreeNode(1) };
        vector<TreeNode *> result;
        for (auto tree : generateTrees(n - 1)) {
            TreeNode *newNode = new TreeNode(n);
            newNode->left = copyTree(tree);
            result.push_back(newNode);
            TreeNode *node = tree;
            while (node) {
                // add the new tree
                newNode = new TreeNode(n);
                newNode->left = node->right;
                node->right = newNode;
                result.push_back(copyTree(tree));
                // reverse to the original tree and check next level
                node->right = newNode->left;
                delete newNode;
                node = node->right;
            }
            eraseTree(tree);
        }
        return result;
    }
};