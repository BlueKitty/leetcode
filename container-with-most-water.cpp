class Solution {
public:
    int maxArea(vector<int> &height) {
        int num_bars = height.size();
        int left = 0, right = num_bars - 1, max_area = 0;
        while (left < right) {
            max_area = max(max_area, min(height[left], height[right]) * (right - left));
            if (height[left] < height[right]) {
                // bottle neck is in left;
                int prev_left = height[left];
                while ((++left) < right && height[left] < prev_left) continue;
                // area is impossible to increase if next left candidate is shorter
            } else {
                // bottle neck is in right;
                int prev_right = height[right];
                // area is impossible to increase if next right candidate is shorter
                while ((--right) > left && height[right] < prev_right) continue;
            }
        }
        return max_area;
    }
};