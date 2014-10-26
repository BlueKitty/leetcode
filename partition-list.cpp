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
        ListNode *new_list = NULL;
        ListNode *new_list_end = NULL;
        ListNode dummy_node(0);
        dummy_node.next = head;
        ListNode *current_node = &dummy_node;
        while (true) {
            if (current_node->next == NULL) {
                // link the two lists
                current_node->next = new_list;
                break;
            } else if (current_node->next->val >= x) {
                ListNode *node_to_move = current_node->next;
                if (node_to_move == head)
                    head = head->next;
                current_node->next = current_node->next->next;
                node_to_move->next = NULL;
                if (new_list == NULL) {
                    new_list = node_to_move;
                    new_list_end = node_to_move;
                } else {
                    new_list_end->next = node_to_move;
                    new_list_end = node_to_move;
                }
            } else {
                current_node = current_node->next;
            }
        }
        return head != NULL ? head: new_list;
    }
};