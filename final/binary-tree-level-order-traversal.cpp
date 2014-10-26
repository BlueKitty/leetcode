/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/* The idea of using cur_level_node_left is from Pumbaa */
class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > result;
        queue<TreeNode *> bfs_queue;
        bfs_queue.push(root);
        int cur_level_node_left = 0;
        while (!bfs_queue.empty()) {
            if (cur_level_node_left == 0) {
                result.push_back({});
                cur_level_node_left = bfs_queue.size();
            }
            TreeNode *cur_node = bfs_queue.front();
            bfs_queue.pop();
            if (cur_node) {
                result.back().push_back(cur_node->val);
                bfs_queue.push(cur_node->left);
                bfs_queue.push(cur_node->right);
            }
            cur_level_node_left--;
        }
        if (result.back().empty()) result.pop_back();
        return result;
    }
};