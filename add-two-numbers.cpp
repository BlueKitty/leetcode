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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode dummy_head(-1), *tail = &dummy_head;
        int carry = 0;
        while (l1 || l2) {
            int l1_digit = l1 ? l1->val : 0;
            int l2_digit = l2 ? l2->val : 0;
            int sum = l1_digit + l2_digit + carry;
            carry = sum / 10;
            tail->next = new ListNode(sum % 10);
            tail = tail->next;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        if (carry) tail->next = new ListNode(carry);
        return dummy_head.next;
    }
};