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
        ListNode *it = head;
        int i = 0, n = 0;
        if (head == NULL) 
            return head;
        while (true) {
            n++;
            if (it->next == NULL) {
                it->next = head;
                break;
            }
            it = it->next;
        }
        while (i < ((n - k % n) % n)) {
            it = it->next;
            i++;
        }
        head = it->next;
        it->next = NULL;
        return head;
    }
};