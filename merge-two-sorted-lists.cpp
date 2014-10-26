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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (l1 == NULL) {
            return l2;
        } else if (l2 == NULL) {
            return l1;
        } else {
            // l1 and l2 are both non-empty
            ListNode *newList = NULL;
            ListNode *newList_end = NULL;
            while (l1 != NULL && l2 != NULL) {
                ListNode **leading_list_ptr = l1->val < l2->val ? &l1 : &l2;
                if (newList != NULL) {
                    newList_end->next = *leading_list_ptr;
                    newList_end = newList_end->next;
                    *leading_list_ptr = (*leading_list_ptr)->next;
                    newList_end->next = NULL;
                } else {
                    newList = *leading_list_ptr;
                    newList_end = *leading_list_ptr;
                    *leading_list_ptr = (*leading_list_ptr)->next;
                    newList_end->next = NULL;
                }
            }
            if (l1 != NULL) {
                newList_end->next = l1;
            } else if (l2 != NULL) {
                newList_end->next = l2;
            }
            return newList;
        }
    }
};