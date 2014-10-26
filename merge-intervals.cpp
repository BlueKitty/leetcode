/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

class Solution {
public:
    static bool interval_less_than(Interval i, Interval j) { return i.start < j.start; }
    vector<Interval> merge(vector<Interval> &intervals) {
        sort(intervals.begin(), intervals.end(), interval_less_than);
        vector<Interval> results;
        int current_start = INT_MIN;
        int current_end = INT_MIN;
        for (int i = 0; i < intervals.size(); i++) {
            if (intervals[i].start > current_end) {
                // previous interval is not overlapping with the new
                if (current_start != INT_MIN) {
                    // if previous interval is not the dummy one, push it into the result
                    results.push_back(Interval(current_start, current_end));
                }
                current_start = intervals[i].start;
                current_end = intervals[i].end;
            } else {
                // intervals[i].start < current_end
                // next interval is overlapping with the previous one, update
                current_end = intervals[i].end > current_end ? intervals[i].end : current_end;
            }
        }
        // the final merges interval is not pushed into the results, push it
        if (current_start != INT_MIN) {
            results.push_back(Interval(current_start, current_end));
        }
        return results;
    }
};