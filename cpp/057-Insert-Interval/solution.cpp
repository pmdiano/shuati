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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        int insertPos = 0;
        vector<Interval> result;

        for (int i = 0; i < intervals.size(); i++) {
            if (intervals[i].end < newInterval.start) {
                result.push_back(intervals[i]);
                insertPos++;
            } else if (intervals[i].start > newInterval.end) {
                result.push_back(intervals[i]);
            } else {
                newInterval.start = min(newInterval.start, intervals[i].start);
                newInterval.end = max(newInterval.end, intervals[i].end);
            }
        }

        result.insert(result.begin() + insertPos, newInterval);
        return result;
    }
};