/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/* Iterative solution from Pumbaa */
class Solution {
public:
    void flatten(TreeNode *root) {
        stack<TreeNode *> preorder_stack;
        TreeNode *cur_node = root, **prev_node_ptr = &root;
        while (!preorder_stack.empty() || cur_node) {
            if (cur_node) {
                *prev_node_ptr = cur_node;
                TreeNode* next_node = cur_node->left;
                cur_node->left = NULL;
                preorder_stack.push(cur_node->right);
                prev_node_ptr = &cur_node->right;
                cur_node = next_node;
            } else {
                cur_node = preorder_stack.top();
                preorder_stack.pop();
            }
        }
    }
};

/* Using ptr-to-ptr to avoid dummy head */
class Solution {
public:
    void flatten(TreeNode *root) {
        stack<TreeNode *> preorder_stack;
        TreeNode *cur_node = root, **prev_node_ptr = &root;
        while (!preorder_stack.empty() || cur_node) {
            if (cur_node) {
                *prev_node_ptr = cur_node;
                TreeNode* next_node = cur_node->left;
                cur_node->left = NULL;
                preorder_stack.push(cur_node->right);
                prev_node_ptr = &cur_node->right;
                cur_node = next_node;
            } else {
                cur_node = preorder_stack.top();
                preorder_stack.pop();
            }
        }
        
    }
};

