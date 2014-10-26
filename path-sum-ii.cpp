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
    void check_path(TreeNode *root, vector<int> &path_vector, int sum, int target,
                    vector<vector<int> > &result) {
        if (root == NULL) {
            return;
        }
        int path_sum = sum + root->val;
        path_vector.push_back(root->val);
        if (root->left == NULL && root->right == NULL) {
            // leaf node
            if (path_sum == target) {
                result.push_back(path_vector);
            }
        } else {
            check_path(root->left, path_vector, path_sum, target, result);
            check_path(root->right, path_vector, path_sum, target, result);
        }
        path_vector.pop_back();
    }
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > result;
        vector<int> path_vector;
        check_path(root, path_vector, 0, sum, result);
        return result;
    }
};