class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        vector<int> ipos, jpos;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j]) {
                    ipos.push_back(i);
                    jpos.push_back(j);
                }
            }
        }

        int c = ipos.size(), sum = 0, mid = ipos[c/2];
        for (int x : ipos) {
            sum += abs(x - mid);
        }

        sort(jpos.begin(), jpos.end());
        mid = jpos[c/2];
        for (int y : jpos) {
            sum += abs(y - mid);
        }

        return sum;
    }
};