class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        vector<unsigned char> visited(n, 0);
        vector<vector<int>> graph(n);
        for (auto& e : edges) {
            graph[e.first].push_back(e.second);
            graph[e.second].push_back(e.first);
        }

        queue<int> q;
        q.push(0); visited[0] = 1;
        while (!q.empty()) {
            int curr = q.front(); q.pop();
            for (int neighbor : graph[curr]) {
                if (visited[neighbor] == 1) return false;
                if (visited[neighbor] == 0) { q.push(neighbor); visited[neighbor] = 1; }
            }
            visited[curr] = 2;
        }

        for (int v : visited) {
            if (v == 0) return false;
        }

        return true;
    }
};