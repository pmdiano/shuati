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
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> ans;
        if (intervals.empty()) {
            return ans;
        }

        sort(intervals.begin(), intervals.end(), [](const Interval& lhs, const Interval& rhs) -> bool {
            return lhs.start < rhs.start;
        });

        Interval prev = intervals[0];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i].start > prev.end) {
                ans.push_back(prev);
                prev = intervals[i];
            } else {
                prev.end = max(prev.end, intervals[i].end);
            }
        }
        ans.push_back(prev);

        return ans;
    }
};
