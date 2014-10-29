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
        if (intervals.size() == 0) return {};
        sort(intervals.begin(), intervals.end(), interval_less_than);
        vector<Interval> results;
        int current_start = intervals[0].start, current_end = intervals[0].end;
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i].start > current_end) { /* not overlapping with previous interval */
                results.push_back(Interval(current_start, current_end));
                current_start = intervals[i].start;
                current_end = intervals[i].end;
            } else { /* overlapping */
                current_end = max(current_end, intervals[i].end);
            }
        }
        results.push_back(Interval(current_start, current_end)); /* push in final interval */
        return results;
    }
};