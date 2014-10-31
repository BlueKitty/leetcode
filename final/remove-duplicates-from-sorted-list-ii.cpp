/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode **cur = &head;
        while (*cur) {
            int cur_val = (*cur)->val;
            if ((*cur)->next && (*cur)->next->val == cur_val) {
                while (*cur && (*cur)->val == cur_val) {
                    ListNode *next_node = (*cur)->next;
                    delete *cur;
                    *cur = next_node;
                };
            } else {
                cur = &((*cur)->next);
            }
        }
        return head;
    }
};