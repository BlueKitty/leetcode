class Solution {
public:
    int findMin(vector<int> &num) {
        if (num.size() == 0) return -1;
        int left = 0, right = num.size() - 1, min_val = num[0];
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (num[mid] < num[left]) {
                min_val = min(min_val, num[mid]);
                right = mid - 1;
            } else if (num[mid] > num[left]) {
                min_val = min(min_val, num[left]);
                left = mid + 1;
            } else {
                min_val = min(min_val, num[left]);
                left++;
            }
        }
        return min_val;
    }
};