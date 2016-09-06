class Solution {
public:
    bool isReflected(vector<pair<int, int>>& points) {
        if (points.empty()) {
            return true;
        }

        int xleft = INT_MAX, xright = INT_MIN;
        set<pair<int, int>> s;
        for (auto &p : points) {
            s.insert(p);
            xleft = min(xleft, p.first);
            xright = max(xright, p.first);
        }

        int xt = xleft + xright;
        for (auto p : points) {
            p.first = xt - p.first;
            if (!s.count(p)) {
                return false;
            }
        }
        return true;
    }
};