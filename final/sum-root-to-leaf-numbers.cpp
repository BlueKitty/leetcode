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
    void add_number(TreeNode *root, int number, int &sum) {
        if (root == NULL) return;
        int new_number = number * 10 + root->val;
        if (root->left == NULL && root->right == NULL) {
            sum += new_number;
        } else {
            add_number(root->left, new_number, sum);
            add_number(root->right, new_number, sum);
        }
    }
    int sumNumbers(TreeNode *root) {
        int sum = 0;
        add_number(root, 0, sum);
        return sum;
    }
};