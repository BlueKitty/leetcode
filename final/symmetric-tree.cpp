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
        if (root == NULL) return true;
        vector<TreeNode *> left_stack, right_stack;
        left_stack.push_back(root->left);
        right_stack.push_back(root->right);
        while (!left_stack.empty() && !right_stack.empty()) {
            TreeNode *left_node = left_stack.back();
            left_stack.pop_back();
            TreeNode *right_node = right_stack.back();
            right_stack.pop_back();
            if (left_node && right_node) {
                if (left_node->val != right_node->val) return false;
                left_stack.push_back(left_node->left);
                left_stack.push_back(left_node->right);
                right_stack.push_back(right_node->right);
                right_stack.push_back(right_node->left);
            } else if (left_node || right_node) {
                return false;
            }
        }
        return (left_stack.empty() && right_stack.empty());
    }
};

class Solution {
public:
    bool isMirror(TreeNode *l, TreeNode *r) {
        if (l && r)
            return (l->val == r->val && isMirror(l->left, r->right) && isMirror(r->left, l->right));
        else if (!l && !r)
            return true;
        else
            return false;
    }
    bool isSymmetric(TreeNode *root) {
        if (root == NULL) return true;
        return isMirror(root->left, root->right);
    }
};
