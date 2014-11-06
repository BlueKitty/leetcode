/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
/** 
 * There are O(n) solutions accepted without doing binary search. Those are
 * straightforward to implement and does not utilize the fact that intervals are sorted
 * and non-overlapping. This binary search version is supposed to run in O(logN) but note
 * that deletion of nodes can be up to O(n) times so that the worse case is still O(n).
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
         /* search for the intervals that contains the boudaries of the new interval */
        int n = intervals.size(), first_idx = -1, second_idx = n;
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (intervals[mid].start <= newInterval.start) {
                left = mid + 1;
                first_idx = mid;
            } else {
                right = mid - 1;
            }
        }
        left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (intervals[mid].end >= newInterval.end) {
                right = mid - 1;
                second_idx = mid;
            } else {
                left = mid + 1;
            }
        }
        bool lower_bound_in_interval = first_idx >= 0 && intervals[first_idx].end >= newInterval.start;
        bool upper_bound_in_interval = second_idx < n && intervals[second_idx].start <= newInterval.end;
        /* remove intervals in between */
        if (first_idx < second_idx)
            intervals.erase(intervals.begin() + first_idx + 1, intervals.begin() + second_idx);
        if (!lower_bound_in_interval && !upper_bound_in_interval) {
            intervals.insert(intervals.begin() + first_idx + 1, newInterval);
        } else if (lower_bound_in_interval && upper_bound_in_interval) {
            if (first_idx != second_idx) {
                intervals[first_idx].end = intervals[first_idx + 1].end;
                intervals.erase(intervals.begin() + first_idx + 1);
            }
        } else if (lower_bound_in_interval && !upper_bound_in_interval) {
            intervals[first_idx].end = newInterval.end;
        } else if (!lower_bound_in_interval && upper_bound_in_interval) {
            intervals[first_idx + 1].start = newInterval.start;
        }
        return intervals;
    }
};