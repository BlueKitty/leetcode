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
    TreeNode *createBST(vector<int> &vec, int start, int end) {
        if (start == end) {
            return new TreeNode(vec[start]);
        } else if (start < end) {
            int mid = start + (end - start) / 2;
            TreeNode *root = new TreeNode(vec[mid]);
            root->left = createBST(vec, start, mid - 1);
            root->right = createBST(vec, mid + 1, end);
            return root;
        } else if (start > end) {
            return NULL;
        }
    }
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return createBST(num, 0, num.size() - 1);
    }
};