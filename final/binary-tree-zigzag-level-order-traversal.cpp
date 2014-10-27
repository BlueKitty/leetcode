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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > result;
        queue<TreeNode *> bfs_queue;
        int cur_level_node_left = 0;
        bfs_queue.push(root);
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
        for (int i = 1; i < result.size(); i += 2) {
            reverse(result[i].begin(), result[i].end());
        }
        return result;
    }
};