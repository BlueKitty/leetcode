/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/* My original short solution. It is better to understand it by walking
 * through an example, e.g. {1, 2, 3}, 1, 3.
 * The basic idea is to first find the head of reversion region (insert_ptr)
 * and then insert nodes in the reversion region one by one at insert_ptr.
 * The insertion is magically achieved by the two swaps. */
class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (m == n) return head;
        ListNode **insert_ptr = &head;
        for (int i = 0; i < m - 1; ++i) insert_ptr = &((*insert_ptr)->next);
        ListNode **to_move = &((*insert_ptr)->next);
        for (int i = 0; i < n - m; ++i) {
            swap((*to_move), (*insert_ptr));
            swap((*to_move), (*insert_ptr)->next);
        }
        return head;
    }
};