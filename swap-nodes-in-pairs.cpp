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
    ListNode *swapPairs(ListNode *head) {
        if(head == NULL)
            return NULL;
        ListNode **pCur = &head, *next = NULL;
        while(*pCur && (*pCur)->next) {
            next = (*pCur)->next;
            (*pCur)->next = next->next;
            next->next = *pCur;
            *pCur = next;
            pCur = &((*pCur)->next->next);
        }
        return head;
    }
};