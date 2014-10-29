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
    ListNode *insertionSortList(ListNode *head) {
        ListNode **cur_ptr = &head, **to_insert = &head;
        while (*cur_ptr) {
            to_insert = &head;
            while (to_insert != cur_ptr) {
                if ((*to_insert)->val > (*cur_ptr)->val) break;
                to_insert = &((*to_insert)->next);
            }
            if (cur_ptr == to_insert) { /* no need to insert */
                cur_ptr = &((*cur_ptr)->next);
            } else { /* insert the node *cur_ptr at to_insert */
                swap(*cur_ptr, *to_insert);
                swap(*cur_ptr, (*to_insert)->next);
            }
        }
        return head;
    }
};