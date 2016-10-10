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
    int minMeetingRooms(vector<Interval>& intervals) {
        map<int, int> m;
        for (auto &a : intervals) {
            m[a.start]++;
            m[a.end]--;
        }
        int res = 0, room = 0;
        for (auto it = m.begin(); it != m.end(); it++) {
            res = max(res, room += it->second);
        }
        return res;
    }
};