class Solution {
    struct Line {
        int k_denom;
        int k_num;
        int y0_denom;
        int y0_num;
        Line() : k_denom(0), k_num(0), y0_denom(0), y0_num(0) {}
        bool operator<(const Line& l2) const {
            if (k_denom != l2.k_denom)
                return k_denom < l2.k_denom;
            if (k_num != l2.k_num)
                return k_num < l2.k_num;
            if (y0_denom != l2.y0_denom)
                return y0_denom < l2.y0_denom;
            return y0_num < l2.y0_num;
        }
        bool pass_point(Point& p) {
        	if (k_denom == 0)
        		return p.x == y0_denom;
        	if (k_num == 0)
        		return p.y == y0_num;
        	return p.y*k_denom == (p.x*k_num + y0_num);
        }
    };
    
    int gcd(int a, int b) {
        // Assume both a and b are positive integers
        if (a < 0) a = -a;
        if (b < 0) b = -b;
        int tmp;
        while (a % b) {
            tmp = b;
            b = a % b;
            a = tmp;
        }
        return b;
    }
    
    Line get_line(Point& p1, Point& p2) {
        Line line;
        if (p1.x == p2.x) {
            line.k_num = 1;
            line.k_denom = 0;
            line.y0_num = 0;
            line.y0_denom = p1.x;
        }
        else if (p1.y == p2.y) {
            line.k_num = 0;
            line.k_denom = 1;
            line.y0_num = p1.y;
            line.y0_denom = 0;
        }
        else {
            int g = gcd(p2.y - p1.y, p2.x - p1.x);
            line.k_denom = (p2.x - p1.x) / g;
            line.k_num = (p2.y - p1.y) / g;
            if (line.k_denom < 0) {
                line.k_denom = - line.k_denom;
                line.k_num = - line.k_num;
            }
            line.y0_num = line.k_denom * p2.y - line.k_num * p2.x;
            line.y0_denom = line.k_denom;
        }
        return line;
    }
    
public:
    int maxPoints(vector<Point>& points) {
        if (points.size() < 3)
            return points.size();

        int nLine = 0;
        Line l;
        std::map<Line, int> hough;
        for (int i = 0; i < points.size(); i++)
            for (int j = i+1; j < points.size(); j++) {
                Line line = get_line(points[i], points[j]);
                int tmp = ++hough[line];
                if (tmp > nLine) {
                    nLine = tmp;
                    l = line;
                }
            }

        int ans = 0;
        for (int i = 0; i < points.size(); i++)
        	if (l.pass_point(points[i]))
        		ans++;
        return ans;
    }
};