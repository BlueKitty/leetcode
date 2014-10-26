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
    void level_traverse(TreeNode *root, int level, vector<vector<int> > &record) {
        if (root == NULL) {
            return;
        } else {
            if (level >= record.size()) {
                record.resize(level + 1);
            }
            record[level].push_back(root->val);
            level_traverse(root->left, level+1, record);
            level_traverse(root->right, level+1, record);
            return;
        }
    }
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> > result;
        level_traverse(root, 0, result);
        reverse(result.begin(), result.end());
        return result;
    }
};