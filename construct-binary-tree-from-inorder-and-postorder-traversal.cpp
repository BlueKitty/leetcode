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
    TreeNode *build_sub_tree(vector<int> &postorder, int post_start, int post_end,
                             vector<int> &inorder, int in_start, int in_end) {
        if (post_start > post_end) {
            return NULL;
        } else {
            int root_val = postorder[post_end];
            int root_index_inorder = in_start;
            while (inorder[root_index_inorder] != root_val) {root_index_inorder++;}
            int left_tree_end_postorder = post_start + (root_index_inorder - in_start) - 1;
            TreeNode *root = new TreeNode(root_val);
            root->left = build_sub_tree(postorder, post_start, left_tree_end_postorder,
                                        inorder, in_start, root_index_inorder - 1);
            root->right = build_sub_tree(postorder, left_tree_end_postorder + 1, post_end - 1,
                                         inorder, root_index_inorder + 1, in_end);
            return root;
        }
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return build_sub_tree(postorder, 0, postorder.size() - 1,
                              inorder, 0, inorder.size() - 1);
    }
};