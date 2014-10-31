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
    void recoverTree(TreeNode *root) {
        if (root == NULL) return;
        TreeNode dummy_min_node(INT_MIN);
        TreeNode *first = NULL, *second = NULL, *prev = &dummy_min_node;
        stack<pair<TreeNode *, bool> > inorder_stack;
        inorder_stack.push({root, false});
        while (!inorder_stack.empty()) {
            TreeNode *cur = inorder_stack.top().first;
            if (inorder_stack.top().second) {
                // left subtree visited
                inorder_stack.pop();
                if (cur->val < prev->val) {
                    if (!first) first = prev;
                    second = cur;
                }
                if (cur->right) inorder_stack.push({cur->right, false});
                prev = cur;
            } else {
                // left subtree unvisited
                inorder_stack.top().second = true; // set visited
                if (cur->left) inorder_stack.push({cur->left, false});
            }
        }
        swap(first->val, second->val);
    }
};