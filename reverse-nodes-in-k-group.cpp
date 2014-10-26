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
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (!head) return head;
        ListNode **group_head_ptr = &head;
        ListNode *group_tail = head;
        for (int i = 0; i < k - 1; ++i) {
            group_tail = group_tail->next;
            if (!group_tail) return head;
        }
        while (group_tail) {
            ListNode **next_group_head_ptr = &(*group_head_ptr)->next;
            while (*group_head_ptr != group_tail) {
                ListNode *next_head = (*group_head_ptr)->next;
                (*group_head_ptr)->next = group_tail->next;
                group_tail->next = *group_head_ptr;
                (*group_head_ptr) = next_head;
            }
            group_head_ptr = next_group_head_ptr;
            group_tail = *group_head_ptr;
            if (!(*group_head_ptr)) break;
            for (int i = 0; i < k - 1; ++i) {
                group_tail = group_tail->next;
                if (!group_tail) break;
            }
        }
        return head;
    }
};