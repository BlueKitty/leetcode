class Solution {
public:
    int findMin(vector<int> &num) {
        int n = num.size(), left = 0, right = n - 1, min = num[0];
        while (left <= right) {
            int mid = (left + right) / 2;
            if (num[mid] < num[0]) {
                min = num[mid];
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return min;
    }
};