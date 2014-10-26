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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (m == n) return head;
        ListNode **reversion_head = &head;
        int num_steps_to_first = m - 1;
        while (num_steps_to_first) {
            reversion_head = &((*reversion_head)->next);
            num_steps_to_first--;
        }
        ListNode **reversion_tail = &((*reversion_head)->next);
        int num_to_reverse = n - m;
        ListNode *current_head = *reversion_head;
        ListNode *next_node = *reversion_tail;
        while (num_to_reverse) {
            (*reversion_tail) = next_node->next;
            (*reversion_head) = next_node;
            next_node->next = current_head;
            current_head = next_node;
            next_node = *reversion_tail;
            num_to_reverse--;
        }
        return head;
    }
};