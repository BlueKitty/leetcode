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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode dummy_head(-1), *early = &dummy_head, *late = &dummy_head;
        dummy_head.next = head;
        for (int i = 0; i <= n; ++i) early = early->next;
        while (early) {
            early = early->next;
            late = late->next;
        }
        ListNode *to_remove = late->next;
        if (to_remove) {
            late->next = to_remove->next;
            delete to_remove;
        }
        return dummy_head.next;
    }
};