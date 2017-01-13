class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if (gas.size() != cost.size() || gas.empty()) {
            return -1;
        }

        int N = gas.size(), least = INT_MAX, m;
        vector<int> tank(N, 0);
        
        for (int i = 1; i <= N; i++) {
            tank[i%N] = tank[i-1] + gas[i-1] - cost[i-1];
            if (tank[i%N] < least) {
                least = tank[i%N];
                m = i%N;
            }
        }

        if (tank[0] >= 0) {
            return m;
        } else {
            return -1;
        }
    }
};