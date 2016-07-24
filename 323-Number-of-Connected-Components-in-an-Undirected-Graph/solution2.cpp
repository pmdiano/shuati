class Solution {
    void bfs(vector<vector<int>>& graph, int i, vector<unsigned char>& visited) {
        queue<int> q;
        q.push(i); visited[i] = 1;
        while (!q.empty()) {
            i = q.front(); q.pop();
            for (int neighbor : graph[i]) {
                if (!visited[neighbor]) {
                    q.push(neighbor);
                    visited[neighbor] = 1;
                }
            }
        }
    }

public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        if (n <= 0) return 0;
        vector<vector<int>> graph(n);
        vector<unsigned char> visited(n, 0);

        for (auto& e : edges) {
            graph[e.first].push_back(e.second);
            graph[e.second].push_back(e.first);
        }

        int count = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                count++;
                bfs(graph, i, visited);
            }
        }

        return count;
    }
};