/* Solution from http://www.geeksforgeeks.org/largest-rectangle-under-histogram/ */
class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        int max_area = 0, i = 0, n = height.size();
        stack<int> bar_stack;
        while (i < n || !bar_stack.empty()) {
            if (bar_stack.empty() || (i < n && height[i] > height[bar_stack.top()])) {
                bar_stack.push(i++);
            } else {
                int min_height = height[bar_stack.top()];
                bar_stack.pop();
                int left_bound = bar_stack.empty() ? -1 : bar_stack.top();
                max_area = max(max_area, min_height * (i - left_bound - 1));
            }
        }
        return max_area;
    }
};