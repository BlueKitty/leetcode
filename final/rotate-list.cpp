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
    ListNode *rotateRight(ListNode *head, int k) {
        ListNode **cur_ptr = &head, **cut_point = &head;
        int n = 0, cut_offset = k;
        while (*cur_ptr) {
            n++;
            cur_ptr = &((*cur_ptr)->next);
        }
        if (n == 0 || k % n == 0) return head;
        cut_offset = n - k % n;
        while (cut_offset > 0) {
            cut_point = &((*cut_point)->next);
            cut_offset--;
        }
        ListNode *new_head = *cut_point;
        *cur_ptr = head;
        *cut_point = NULL;
        return new_head;
    }
};