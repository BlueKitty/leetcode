class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return 0;
        int m = matrix.size(), n = matrix[0].size(), max_area = 0;
        vector<int> height(n, 0);
        for (int i = 0; i < m; ++i) {
            stack<int> s;
            for (int j = 0; j < n; ++j)
            	height[j] = matrix[i][j] == '1' ? height[j] + 1 : 0;
            int j = 0;
            while (j < n) {
                if (s.empty() || height[s.top()] < height[j]) {
                    s.push(j++);
                } else {
                    int height_top = height[s.top()];
                    s.pop();
                    int left_bound = s.empty() ? -1 : s.top();
                    max_area = max(max_area, height_top * (j - left_bound - 1));
                }
            }
            while (!s.empty()) {
                int height_top = height[s.top()];
                s.pop();
                int left_bound = s.empty() ? -1 : s.top();
                max_area = max(max_area, height_top * (j - left_bound - 1));
            }
        }
        return max_area;
    }
};