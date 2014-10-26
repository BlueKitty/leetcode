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
    void traverse(TreeNode *root, int level, vector<list<int> > &record) {
        if (root == NULL) return;
        if (record.size() == level) record.push_back({});
        if (level % 2 == 0) record[level].push_back(root->val);
        else record[level].push_front(root->val);
        traverse(root->left, level + 1, record);
        traverse(root->right, level + 1, record);
        return;
    }
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<list<int> > record;
        traverse(root, 0, record);
        vector<vector<int> > result(record.size());
        for (int i = 0; i < record.size(); i++) {
            for (int num : record[i]) {
                result[i].push_back(num);
            }
        }
        return result;
    }
};