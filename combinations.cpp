class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        list<vector<int> > result_queue;
        vector<vector<int> > result;
        if (k > n || k == 0) return result;
        for (int i = 1; i <= n; i++) {
            result_queue.push_back(vector<int>(1, i));
        }
        while (result_queue.front().size() < k) {
            vector<int> base = result_queue.front();
            int base_size = base.size();
            // there are (k - base_size - 1) more slots after adding one more
            // and if we select a number bigger
            // than n - (k - base_size - 1), there will only be less than
            // (k - base_size - 1) numbers left, which is impossible.
            int max_next = n - (k - base_size - 1);
            for (int i = base.back() + 1; i <= max_next; ++i) {
                vector<int> new_vector = base;
                new_vector.push_back(i);
                result_queue.push_back(new_vector);
            }
            result_queue.pop_front();
        }
        for (list<vector<int> >::iterator it = result_queue.begin();
             it != result_queue.end(); ++it) {
            result.push_back(*it);
        }
        return result;
    }
};