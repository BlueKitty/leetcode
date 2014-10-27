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

/* O(n) solution from http://leetcode.com/2010/11/convert-sorted-list-to-balanced-binary.html
 * the idea is bottom-up, matching recursion stack with in-order traversal
 */
class Solution {
public:
    TreeNode *convert(ListNode *&head, int begin, int end) {
        if (begin > end) return NULL;
        int mid = begin  + (end - begin) / 2;
        TreeNode *left_subtree = convert(head, begin, mid - 1);
        TreeNode *tree = new TreeNode(head->val);
        tree->left = left_subtree;
        head = head->next;
        tree->right = convert(head, mid + 1, end);
        return tree;
    }
    TreeNode *sortedListToBST(ListNode *head) {
        int i = 0;
        ListNode *node = head;
        while (node) { i++; node = node->next; }
        return convert(head, 0, i - 1);
    }
};

/* Naive O(nlog(n)) top-down solution */
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