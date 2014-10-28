/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/* Using ptr-to-ptr to avoid dummy head */
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode **ahead = &head, **behind = &head;
        for (int i = 0; i < n; ++i) ahead = &((*ahead)->next);
        while (*ahead) {
            ahead = &((*ahead)->next);
            behind = &((*behind)->next);
        }
        ListNode *to_remove = *behind;
        *behind = to_remove->next;
        delete to_remove;
        return head;
    }
};

/* Using dummy head, arguably less error-prone */
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode dummy_head(-1), *ahead = &dummy_head, *behind = &dummy_head;
        dummy_head.next = head;
        for (int i = 0; i <= n; ++i) ahead = ahead->next;
        while (ahead) {
            ahead = ahead->next;
            behind = behind->next;
        }
        ListNode *to_remove = behind->next;
        behind->next = to_remove->next;
        delete to_remove;
        return dummy_head.next;
    }
};