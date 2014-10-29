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
    ListNode *swapPairs(ListNode *head) {
        if(head == NULL) return NULL;
        ListNode **cur_ptr = &head, **next_ptr = NULL;
        while(*cur_ptr && (*cur_ptr)->next) {
            next_ptr = &((*cur_ptr)->next);
            swap(*cur_ptr, *next_ptr);
            swap((*cur_ptr)->next, (*next_ptr)->next);
            cur_ptr = next_ptr;
        }
        return head;
    }
};