/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head) return NULL;
        RandomListNode *old_cur = head, *new_cur = NULL;
        while (old_cur) {
            new_cur = new RandomListNode(old_cur->label);
            new_cur->random = old_cur->next;
            new_cur->next = old_cur->next;
            old_cur->next = new_cur;
            old_cur = new_cur->next;
        }
        RandomListNode *new_head = head->next;
        old_cur = head;
        while (old_cur) {
            new_cur = old_cur->next;
            if (old_cur->random) new_cur->random = old_cur->random->next;
            else new_cur->random = NULL;
            old_cur = new_cur->next;
        }
        old_cur = head;
        while (old_cur) {
            new_cur = old_cur->next;
            old_cur->next = new_cur->next;
            if (old_cur->next) new_cur->next = old_cur->next->next;
            old_cur = old_cur->next;
        }
        return new_head;
    }
};