/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/* This again use the ptr-to-ptr trick and the double swap for insertion. */
class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode *cur = head;
        int n = 0;
        while (cur) {
            cur = cur->next;
            n++;
        }
        ListNode **insertion_point = &head;
        for (int i = 0; n - i >= k; i += k) {
            ListNode **to_move = &((*insertion_point)->next);
            for (int j = 0; j < k - 1; ++j) {
                swap(*insertion_point, *to_move);
                swap((*insertion_point)->next, *to_move);
            }
            insertion_point = to_move;
        }
        return head;
    }
};