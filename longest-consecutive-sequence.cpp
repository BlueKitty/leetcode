class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_map<int, int> sequence;
        for (auto i : num) {
            if (sequence.find(i) != sequence.end()) continue;
            sequence[i] = i;
            if (sequence.find(i - 1) != sequence.end()) {
                sequence[i] = sequence[i - 1];
                sequence[sequence[i]] = i;
            }
            if (sequence.find(i + 1) != sequence.end()) {
                int tail = sequence[i + 1];
                sequence[tail] = sequence[i];
                sequence[sequence[i]] = tail;
            }
        }
        int longest = 0;
        for (auto seq : sequence) {
            longest = max(longest, seq.second - seq.first);
        }
        return longest + 1;
    }
};