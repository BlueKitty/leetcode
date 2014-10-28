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
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *current_node = head;
        while (current_node != NULL) {
            if (current_node->next == NULL) break;
            if (current_node->val == current_node->next->val) {
                ListNode *to_be_deleted = current_node->next;
                current_node->next = current_node->next->next;
                delete to_be_deleted;
            } else {
                current_node = current_node->next;
            }
        }
        return head;
    }
};