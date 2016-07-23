class Solution {
    bool dfs(vector<vector<int>>& edges, int i, vector<int>& visited) {
        if (visited[i] == -1) return false;
        if (visited[i] == 1) return true;

        visited[i] = -1;
        for (int neighbor : edges[i]) {
            if (!dfs(edges, neighbor, visited)) {
                return false;
            }
        }
        visited[i] = 1;
        return true;
    }

public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        if (numCourses <= 0) return false;
        int n = numCourses;
        vector<vector<int>> edges(n);
        vector<int> visited(n, 0);

        for (auto& p : prerequisites) {
            edges[p.second].push_back(p.first);
        }

        for (int i = 0; i < n; i++) {
            if (!dfs(edges, i, visited)) {
                return false;
            }
        }

        return true;
    }
};