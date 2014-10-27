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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode dummy_head(0), *list_end = &dummy_head, **leading_list_ptr;
        while (l1 && l2) {
            leading_list_ptr = l1->val < l2->val ? &l1 : &l2;
            list_end->next = *leading_list_ptr;
            list_end = list_end->next;
            *leading_list_ptr = (*leading_list_ptr)->next;
        }
        list_end->next = l1 ? l1 : l2;
        return dummy_head.next;
    }
};