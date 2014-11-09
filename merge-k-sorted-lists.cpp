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
    static bool greater(ListNode *a, ListNode *b) {
        return a->val > b->val;
    }
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        vector<ListNode *> min_heap;
        min_heap.reserve(lists.size());
        for (int i = 0; i < lists.size(); ++i) {
            if (lists[i] != NULL) {
                min_heap.push_back(lists[i]);
                lists[i] = lists[i]->next;
            }
        }
        make_heap(min_heap.begin(), min_heap.end(), greater);
        ListNode *head = NULL, **tail_ptr = &head;
        while (!min_heap.empty()) {
            *tail_ptr = min_heap.front();
            tail_ptr = &((*tail_ptr)->next);
            pop_heap(min_heap.begin(), min_heap.end(), greater);
            min_heap.pop_back();
            if (*tail_ptr != NULL) {
                min_heap.push_back(*tail_ptr);
                push_heap(min_heap.begin(), min_heap.end(), greater);
            }
        }
        return head;
    }
};