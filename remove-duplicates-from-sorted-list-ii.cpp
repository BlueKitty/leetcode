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
    void remove_node(ListNode **node_ptr) {
        ListNode *node = *node_ptr;
        *node_ptr = node->next;
        delete node;
    }
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode **cur = &head;
        while (*cur) {
            int cur_val = (*cur)->val;
            bool duplication_found = false;
            if ((*cur)->next && (*cur)->next->val == cur_val) {
                // duplicate
                while (*cur && (*cur)->val == cur_val) remove_node(cur);
                duplication_found = true;
            }
            if (!duplication_found) cur = &((*cur)->next);
        }
        return head;
    }
};