/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode *sortedListToBST(ListNode *head) {
        if (head == NULL) return NULL;
        ListNode **fast = &head, **slow = &head;
        while (*fast && (*fast)->next) {
            slow = &((*slow)->next);
            fast = &((*fast)->next->next);
        }
        ListNode *mid_node = *slow;
        TreeNode *root = new TreeNode(mid_node->val);
        *slow = NULL; // temporarily cut the list before the mid node
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(mid_node->next);
        *slow = mid_node; // reconnect the list;
        return root;
    }
};