/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        int res = 0;
        unordered_map<float, int> m;
        for (int i = 0; i < points.size(); ++i) {
            m.clear();
            m[INT_MIN] = 0;
            int duplicate = 1;
            for (int j = 0; j < points.size(); ++j) {
                if (j == i) continue;
                if (points[i].x == points[j].x && points[i].y == points[j].y) {
                    ++duplicate;
                    continue;
                }
                float slope = (points[i].x == points[j].x) ? INT_MAX : (float)(points[j].y - points[i].y) / (points[j].x - points[i].x);
                ++m[slope];
            }
            for (unordered_map<float, int>::iterator it = m.begin(); it != m.end(); ++it) {
                res = max(res, it->second + duplicate);
            }
        }
        return res;
    }
};