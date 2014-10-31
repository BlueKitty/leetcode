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
    vector<TreeNode*> generateTrees(int n) {
        return build_bst_recur(1, n);
    }
    
    vector<TreeNode*> build_bst_recur(int start, int end) {
        if (start > end) return { NULL };
        vector<TreeNode *> result;
        for (int i = start; i <= end; i++) {
            vector<TreeNode*> left_trees = build_bst_recur(start, i - 1);
            vector<TreeNode*> right_trees = build_bst_recur(i + 1, end);
            for (auto l : left_trees) {
                for (auto r : right_trees) {
                    TreeNode* cur_head = new TreeNode(i);
                    cur_head->left = l;
                    cur_head->right = r;
                    result.push_back(cur_head);
                }
            }
        }
        return result;
    }
};