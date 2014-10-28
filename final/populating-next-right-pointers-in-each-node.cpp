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
        if (root == NULL) return;
        TreeLinkNode *head = root;
        TreeLinkNode *current = root;
        while (head->left) {
            while (current) {
                current->left->next = current->right;
                if (current->next)
                    current->right->next = current->next->left;
                current = current->next;
            }
            current = head->left;
            head = current;
        }
    }
};