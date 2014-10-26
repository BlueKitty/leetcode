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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> result;
        if (root == NULL)
            return result;
        vector<int> left_vector = postorderTraversal(root->left);
        vector<int> right_vector = postorderTraversal(root->right);
        result.reserve(left_vector.size() + right_vector.size() + 1);
        result.insert(result.end(), left_vector.begin(), left_vector.end());
        result.insert(result.end(), right_vector.begin(), right_vector.end());
        result.push_back(root->val);
    }
};

/* Iterative postorder traversal */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> result;
        stack<TreeNode *> postorder_stack;
        TreeNode *cur_node = root, *last_visited_node = NULL;
        while (!postorder_stack.empty() || cur_node) {
            if (cur_node) {
                postorder_stack.push(cur_node);
                cur_node = cur_node->left;
            } else {
                TreeNode *peek_node = postorder_stack.top();
                if (peek_node->right && peek_node->right != last_visited_node) {
                    cur_node = peek_node->right;
                } else {
                    result.push_back(peek_node->val);
                    postorder_stack.pop();
                    last_visited_node = peek_node;
                }
            }
        }
        return result;
    }
};

/* Iterative reverse postorder traversal from Pumbaa */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> output;
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode* cur = s.top();
            s.pop();
            if (!cur) {
              continue;
            }
            output.push_back(cur->val);
            s.push(cur->left);
            s.push(cur->right);
        }
        reverse(output.begin(), output.end());
        return output;
    }
};