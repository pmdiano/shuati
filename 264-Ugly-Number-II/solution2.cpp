class Solution {
public:
    int nthUglyNumber(int n) {
        if (n <= 0) {
            return -1;
        }

        vector<int> q2(n+1);
        vector<int> q3(n+1);
        vector<int> q5(n+1);
        q2[0] = 1;
        q3[0] = 1;
        q5[0] = 1;
        int i1 = 0, i2 = 0, i3 = 0;
        int j1 = 1, j2 = 1, j3 = 1;

        int current = 0;
        for (int i = 1; i <= n; i++) {
            current = min(q2[i1], min(q3[i2], q5[i3]));
            if (current == q2[i1]) i1++;
            if (current == q3[i2]) i2++;
            if (current == q5[i3]) i3++;
            q2[j1++] = 2*current;
            q3[j2++] = 3*current;
            q5[j3++] = 5*current;
        }

        return current;
    }
};
