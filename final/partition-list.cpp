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
    ListNode *partition(ListNode *head, int x) {
        ListNode *large_list_head = NULL, **large_list_end_ptr = &large_list_head;
        ListNode **cur_node_ptr = &head;
        while (*cur_node_ptr) {
            if ((*cur_node_ptr)->val >= x) {
                *large_list_end_ptr = *cur_node_ptr;
                *cur_node_ptr = (*cur_node_ptr)->next;
                large_list_end_ptr = &((*large_list_end_ptr)->next);
                *large_list_end_ptr = NULL;
            } else {
                cur_node_ptr = &((*cur_node_ptr)->next);
            }
        }
        *cur_node_ptr = large_list_head; //connect the two lists
        return head;
    }
};