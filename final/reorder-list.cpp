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
        if (!head) return;
        ListNode *front = head, *behind = head;
        while (front && front->next) {
            behind = behind->next;
            front = front->next->next;
        }
        ListNode *new_list = NULL;
        ListNode **cut_point = &(behind->next);
        while (*cut_point) { /* reverse the second half by appending to new_list */
            ListNode *next_node = (*cut_point)->next;
            (*cut_point)->next = new_list;
            new_list = *cut_point;
            *cut_point = next_node;
        }
        front = head;
        while (front && new_list) {
            ListNode *next_new_list_head = new_list->next;
            new_list->next = front->next;
            front->next = new_list;
            front = new_list->next;
            new_list = next_new_list_head;
        }
    }
};