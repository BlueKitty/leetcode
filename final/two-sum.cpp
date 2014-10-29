class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        unordered_map<int, int> record;
        for (int i = 0; i < numbers.size(); ++i) {
            int reminder = target - numbers[i];
            if (record.count(reminder)) return { record[reminder], i + 1 };
            else record[numbers[i]] = i + 1;
        }
    }
};