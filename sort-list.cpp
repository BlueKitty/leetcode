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
    ListNode *sortList(ListNode *head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode *cur = head, **cut_point = &head;
        while (cur && cur->next) { /* cur move forward twice faster */
            cur = cur->next->next;
            cut_point = &((*cut_point)->next);
        }
        cur = *cut_point; /* reuse the variable for second_half of the list */
        *cut_point = NULL; /* cut the list into two halves */
        ListNode *first_half = sortList(head), *second_half = sortList(cur);
        ListNode **cur_ptr = &head; /* starting to merge */
        while(first_half && second_half) {
            if (first_half->val < second_half->val) {
                *cur_ptr = first_half;
                first_half = first_half->next;
            } else {
                *cur_ptr = second_half;
                second_half = second_half->next;
            }
            cur_ptr = &((*cur_ptr)->next);
        }
        if (first_half) *cur_ptr = first_half;
        if (second_half) *cur_ptr = second_half;
        return head;
    }
};