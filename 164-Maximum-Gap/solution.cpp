class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) {
            return 0;
        }

        int vmax = INT_MIN, vmin = INT_MAX;
        for (int x : nums) {
            vmax = max(vmax, x);
            vmin = min(vmin, x);
        }
        if (vmax == vmin) {
            return 0;
        }

        int n = nums.size();
        double width = double(vmax - vmin) / double(n);
        vector<pair<int, int>> buckets(n+1, make_pair(INT_MAX, INT_MIN));
        for (int x : nums) {
            int index = int((x - vmin) / width);
            buckets[index].first = min(buckets[index].first, x);
            buckets[index].second = max(buckets[index].second, x);
        }

        int gap = 0, prev = INT_MIN;
        for (auto& p : buckets) {
            if (p.first != INT_MAX && prev != INT_MIN) {
                gap = max(gap, p.first - prev);
            }
            prev = max(prev, p.second);
        }

        return gap;
    }
};