/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
/* A clean solution from Da-Cheng */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head) return NULL;
        RandomListNode *old_cur = head;
        while (old_cur) {
            RandomListNode *new_node = new RandomListNode(old_cur->label);
            new_node->next = old_cur->next;
            old_cur->next = new_node;
            old_cur = new_node->next;
        }
        for (old_cur = head; old_cur; old_cur = old_cur->next->next)
            old_cur->next->random = old_cur->random ? old_cur->random->next : NULL;
        RandomListNode *new_head = head->next, *new_cur = new_head;
        for (old_cur = head; old_cur; old_cur = old_cur->next, new_cur = new_cur->next) {
            old_cur->next = old_cur->next->next;
            new_cur->next = old_cur->next ? old_cur->next->next : NULL;
        }
        return new_head;
    }
};