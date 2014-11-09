/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
 
/* Note: unordered_map on pair<int, int> needs user-defined hash function */ 
class Solution {
public:
    int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }
    int maxPoints(vector<Point> &points) {
        int max_points = 0;
        for (int i = 0; i < points.size(); ++i) {
            unordered_map<int, unordered_map<int, int>> record;
            int num_duplicates = 1; /* how many points are identical to points[i] */
            int local_max = 0;
            for (int j = i + 1; j < points.size(); ++j) {
                int x_diff = points[j].x - points[i].x, y_diff = points[j].y - points[i].y;
                if (x_diff == 0 && y_diff == 0) {
                    num_duplicates++;
                } else {
                    int divisor = gcd(x_diff, y_diff);
                    x_diff /= divisor;
                    y_diff /= divisor;
                    record[x_diff][y_diff]++;
                    local_max = max(local_max, record[x_diff][y_diff]);
                }
            }
            max_points = max(local_max + num_duplicates, max_points);
        }
        return max_points;
    }
};