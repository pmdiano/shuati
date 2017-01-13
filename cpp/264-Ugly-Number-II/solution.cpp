class Solution {
public:
    int nthUglyNumber(int n) {
        queue<int> q2, q3, q5;
        q2.push(1);
        q3.push(1);
        q5.push(1);

        int current = 0;
        for (int i = 1; i <= n; i++) {
            current = min(q2.front(), min(q3.front(), q5.front()));
            if (q2.front() == current) q2.pop();
            if (q3.front() == current) q3.pop();
            if (q5.front() == current) q5.pop();
            q2.push(2*current);
            q3.push(3*current);
            q5.push(5*current);
        }

        return current;
    }
};
