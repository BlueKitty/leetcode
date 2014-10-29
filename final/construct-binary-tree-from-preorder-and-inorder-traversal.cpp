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
    TreeNode *build_sub_tree(vector<int> &preorder, int pre_start, int pre_end,
                             vector<int> &inorder, int in_start, int in_end) {
        if (pre_start > pre_end) return NULL;
        int root_val = preorder[pre_start], root_index_inorder = in_start;
        while (inorder[root_index_inorder] != root_val) {root_index_inorder++;}
        int left_tree_end_preorder = pre_start + (root_index_inorder - in_start);
        TreeNode *root = new TreeNode(root_val);
        root->left = build_sub_tree(preorder, pre_start + 1, left_tree_end_preorder,
                                    inorder, in_start, root_index_inorder - 1);
        root->right = build_sub_tree(preorder, left_tree_end_preorder + 1, pre_end,
                                     inorder, root_index_inorder + 1, in_end);
        return root;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return build_sub_tree(preorder, 0, preorder.size() - 1,
                              inorder, 0, inorder.size() - 1);
    }
};