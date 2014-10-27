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
    TreeNode *createBST(vector<int> &vec, int begin, int end) {
        if (begin > end) return NULL;
        int mid = begin + (end - begin) / 2;
        TreeNode *root = new TreeNode(vec[mid]);
        root->left = createBST(vec, begin, mid - 1);
        root->right = createBST(vec, mid + 1, end);
        return root;
    }
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return createBST(num, 0, num.size() - 1);
    }
};