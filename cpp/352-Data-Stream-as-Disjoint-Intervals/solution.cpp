/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

bool operator<(const Interval &lhs, const Interval &rhs) {
    return lhs.start < rhs.start;
}

class SummaryRanges {
    set<Interval> s;
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
        Interval interval(val, val);
        set<Interval>:: iterator lb, prev;
        bool no_change = false, merge_prev = false, merge_next = false;

        lb = s.lower_bound(interval);
        if (lb != s.end()) {
            if (lb->start == val) no_change = true;
            else if (lb->start == val+1) merge_next = true;
        }

        prev = lb;
        if (prev != s.begin()) {
            prev--;
            if (prev->end >= val) no_change = true;
            else if (prev->end == val-1) merge_prev = true;
        }

        if (no_change) return;
        if (merge_prev && merge_next) {
            interval.start = prev->start;
            interval.end = lb->end;
            prev = s.erase(prev);
            prev = s.erase(prev);
        } else if (merge_prev) {
            interval.start = prev->start;
            prev = s.erase(prev);
        } else if (merge_next) {
            interval.end = lb->end;
            lb = s.erase(lb);
        }
        s.insert(interval);
    }
    
    vector<Interval> getIntervals() {
        return vector<Interval>(s.begin(), s.end());
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */