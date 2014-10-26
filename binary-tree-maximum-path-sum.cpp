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
    struct Record {
        bool visited;
        int max_half_path;
        Record() : visited(false), max_half_path(INT_MIN) {};
        Record(int half) : visited(false), max_half_path(half) {}
    };
    int maxPathSum(TreeNode *root) {
        if (root == NULL) return 0;
        int max_path = INT_MIN;
        unordered_map<TreeNode *, Record> records;
        stack<TreeNode *> node_stack;
        node_stack.push(root);
        records.insert({root, {root->val}});
        while (!node_stack.empty()) {
            TreeNode *node = node_stack.top();
            if (!records[node].visited) {
                if (node->left) {
                    records.insert({node->left, {node->left->val}});
                    node_stack.push(node->left);
                }
                if (node->right) {
                    records.insert({node->right, {node->right->val}});
                    node_stack.push(node->right);
                }
                records[node].visited = true;
            } else {
                int left_max_half_path = node->left ? records[node->left].max_half_path : 0;
                int right_max_half_path = node->right ? records[node->right].max_half_path : 0;
                int half_path = max(max(left_max_half_path + node->val, right_max_half_path + node->val),
                                    node->val);
                int full_path = left_max_half_path + right_max_half_path + node->val;
                records[node].max_half_path = half_path;
                max_path = max(max_path, max(half_path, full_path));
                node_stack.pop();
            }
        }
        return max_path;
    }
};