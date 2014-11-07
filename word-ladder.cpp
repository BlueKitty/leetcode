/* BFS solution from Da-Cheng */
class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        unordered_set<string> visited;
        queue<pair<string, int>> bfs_queue;
        bfs_queue.push(make_pair(start, 1));
        while (!bfs_queue.empty()) {
            auto &kv = bfs_queue.front();
            string word = kv.first;
            int len = kv.second;
            if (visited.count(word) == 0) {
                visited.insert(word);
                for (int i = 0; i < word.size(); ++i) {
                    char original_c = word[i];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        if (c == original_c) continue;
                        word[i] = c;
                        if (word == end) return len + 1;
                        if (dict.count(word))
                            bfs_queue.push(make_pair(word, len + 1));
                    }
                    word[i] = original_c;
                }
            }
            bfs_queue.pop();
        }
        return 0;
    }
};