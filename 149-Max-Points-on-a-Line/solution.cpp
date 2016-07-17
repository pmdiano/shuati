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
    static int gcd(int a, int b) {
        if (a < 0) a = -a;
        if (b < 0) b = -b;
        while (a % b) {
            int tmp = a % b;
            a = b;
            b = tmp;
        }
        return b;
    }

    static pair<int, int> normalize(pair<int, int> p) {
        // p.second is guaranteed to be non-zero when calling this
        if (p.first == 0) {
            return make_pair(0, 1);
        }
        int cd = gcd(p.first, p.second);
        p.first /= cd;
        p.second /= cd;
        if (p.first < 0) {
            p.first = -p.first;
            p.second = -p.second;
        }
        return p;
    }

    struct Line {
        // ax + by + c = 0
        int a;
        int b;
        int c;
        int d;
        Line() : a(0), b(0), c(0) {}
        Line(int aa, int bb, int cc, int dd) : a(aa), b(bb), c(cc) {}
        Line (Point& p1, Point& p2) {
            if (p1.x == p2.x) {
                a = 1;
                b = 0;
                c = -p1.x;
                return;
            }
            if (p1.y == p2.y) {
                a = 0;
                b = 1;
                c = -p1.y;
                return;
            }

            pair<int, int> k = Solution::normalize(make_pair(p2.y-p1.y, p2.x-p1.x));
            pair<int, int> d = Solution::normalize(make_pair(p2.x*p1.y-p1.x*p2.y, p2.x-p1.x));

            int cd = Solution::gcd(k.second, d.second);
            a = k.first * d.second / cd;
            b = -k.second * d.second / cd;
            c = k.second * d.first / cd;
            if (a < 0) {
                a = -a;
                b = -b;
                c = -c;
            }
        }

        bool operator==(const Line& rhs) const {
            return (a == rhs.a && b == rhs.b && c == rhs.c);
        }

        bool containsPoint(const Point& p) const {
            return a * p.x + b * p.y + c == 0;
        }
    };

    struct LineHasher {
        std::size_t operator()(const Solution::Line& l) const {
            return (hash<int>()(l.a) ^ (hash<int>()(l.b) << 1) >> 1) ^ (hash<int>()(l.c) << 1);
        }
    };

public:
    int maxPoints(vector<Point>& points) {
        if (points.size() <= 1) {
            return points.size();
        }

        int n = 0;
        Line l;
        unordered_map<Line, int, LineHasher> hash;
        for (int i = 1; i < points.size(); i++) {
            for (int j = 0; j < i; j++) {
                Line line(points[i], points[j]);
                if (++hash[line] > n) {
                    n = hash[line];
                    l = line;
                }
            }
        }

        int ans = 0;
        for (Point& p : points) {
            if (l.containsPoint(p)) {
                ans++;
            }
        }
        return ans;
    }
};