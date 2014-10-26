/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode *next_level_head = root, *next_level_tail = root, *current = NULL;
        while (next_level_head) {
            current = next_level_head;
            next_level_head = NULL;
            next_level_tail = NULL;
            while (current) {
                if (!next_level_head) next_level_head = current->left ? current->left : current->right;
                if (current->left) {
                    if (next_level_tail) next_level_tail->next = current->left;
                    next_level_tail = current->left;
                }
                if (current->right) {
                    if (next_level_tail) next_level_tail->next = current->right;
                    next_level_tail = current->right;
                }
                current = current->next;
            }
        }
    }
};