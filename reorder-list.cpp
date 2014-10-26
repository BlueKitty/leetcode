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
    void reorderList(ListNode *head) {
        int n = 0;
        ListNode *it = head;
        if (head == NULL) 
            return;
        while (it != NULL) {
            it = it->next;
            n++;
        }
        int i = 0, pivot = n % 2 == 0? n/2 : n/2 + 1;
        it = head;
        ListNode **it_ptr = NULL;
        while (i < pivot) {
            it_ptr = &(it->next);
            it = it->next;
            i++;
        }
        *it_ptr = NULL;
        ListNode *dh = new ListNode(0); //dummy head for the reverse list of second half
        dh->next = NULL;
        while (it != NULL) {
            ListNode *it_next = it->next;
            it->next = dh->next;
            dh->next = it;
            it = it_next;
        }
        it = head;
        ListNode *it_reverse = dh->next;
        i = 0;
        while (it_reverse != NULL) {
            ListNode *it_next = it->next;
            ListNode *it_reverse_next = it_reverse->next;
            it->next = it_reverse;
            it->next->next = it_next;
            it_reverse = it_reverse_next;
            it = it_next;
        }
        delete dh;
    }
};