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
    enum class EdgeType {
        start,
        end
    };

    struct Edge {
        int pos;
        EdgeType type;
        Edge(): pos(0), type(EdgeType::start) {}
        Edge(int p, EdgeType t) : pos(p), type(t) {}
    };

public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if (intervals.empty()) {
            return 0;
        }

        vector<Edge> edges(intervals.size() * 2);
        for (int i = 0, j = 0; i < intervals.size(); i++) {
            edges[j++] = Edge(intervals[i].start, EdgeType::start);
            edges[j++] = Edge(intervals[i].end, EdgeType::end);
        }
        sort(edges.begin(), edges.end(), [](const Edge& lhs, const Edge& rhs) -> bool {
            if (lhs.pos != rhs.pos) {
                return lhs.pos < rhs.pos;
            } else {
                return lhs.type == EdgeType::end;
            }
        });

        int count = 0, ans = 0;
        for (Edge& e : edges) {
            if (e.type == EdgeType::start) {
                ans = max(ans, ++count);
            } else {
                --count;
            }
        }

        return ans;
    }
};