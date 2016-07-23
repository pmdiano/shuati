class Solution {
    bool dfs(vector<vector<int>>& edges, int i, vector<int>& visited, vector<int>& result) {
        if (visited[i] == -1) return false;
        if (visited[i] == 1) return true;

        visited[i] = -1;
        for (int neighbor : edges[i]) {
            if (!dfs(edges, neighbor, visited, result)) {
                return false;
            }
        }

        visited[i] = 1;
        result.push_back(i);
        return true;
    }

public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> result;
        if (numCourses <= 0) return result;

        int n = numCourses;
        vector<vector<int>> edges(n);
        vector<int> visited(n, 0);
        result.reserve(n);

        for (auto& p : prerequisites) {
            edges[p.second].push_back(p.first);
        }

        for (int i = 0; i < n; i++) {
            if (!dfs(edges, i, visited, result)) {
                return vector<int>();
            }
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
