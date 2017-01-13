class Solution {
    void dfs(vector<vector<int>>& graph, int i, vector<unsigned char>& visited) {
        visited[i] = 1;
        for (int neighbor : graph[i]) {
            if (!visited[neighbor]) {
                dfs(graph, neighbor, visited);
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
                dfs(graph, i, visited);
            }
        }

        return count;
    }
};