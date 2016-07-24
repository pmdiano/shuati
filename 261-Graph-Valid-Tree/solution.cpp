class Solution {
    bool dfs(vector<vector<int>>& graph, int i, int parent, vector<char>& visited) {
        visited[i] = true;
        for (int neighbor : graph[i]) {
            if (neighbor != parent) {
                if (visited[neighbor]) return false;
                if (!dfs(graph, neighbor, i, visited)) return false;
            }
        }
        return true;
    }

public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        if (n <= 0) return false;

        vector<char> visited(n, 0);
        vector<vector<int>> graph(n);
        for (auto& e : edges) {
            graph[e.first].push_back(e.second);
            graph[e.second].push_back(e.first);
        }

        if (!dfs(graph, 0, 0, visited)) {
            return false;
        }
        for (int i = 1; i < n; i++) {
            if (!visited[i]) return false;
        }

        return true;
    }
};