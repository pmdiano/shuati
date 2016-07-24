class Solution {
    vector<int> parent;

    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        if (n <= 0) return 0;
        parent.resize(n);
        for (int i = 0; i < n; i++) { parent[i] = i; }

        int count = n;
        for (auto& e : edges) {
            int px = find(e.first);
            int py = find(e.second);
            if (px != py) {
                parent[py] = px;
                count--;
            }
        }

        return count;
    }
};