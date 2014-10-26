/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/* Iterative solution from Pumbaa
 * Idea: the last traversed node must not have a right child.
 */
/* It is possible to not use a stack (Morris traversal)
 * http://comsci.liu.edu/~murali/algo/Morris.htm
 * http://stackoverflow.com/questions/5502916/explain-morris-inorder-tree-traversal-without-using-stacks-or-recursion
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;
        stack<TreeNode *> inorder_stack;
        TreeNode *cur_node = root;
        while (!inorder_stack.empty() || cur_node) {
            if (cur_node) {
                inorder_stack.push(cur_node);
                cur_node = cur_node->left;
            } else {
                cur_node = inorder_stack.top();
                inorder_stack.pop();
                result.push_back(cur_node->val);
                cur_node = cur_node->right;
            }
        }
        return result;
    }
};

/* Short recursive solution */
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