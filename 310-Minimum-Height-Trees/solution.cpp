class Solution {
    void dfs(vector<vector<int>>& graph, int node, vector<char>& visited, vector<int>& path, vector<int>& longest) {
        visited[node] = 1;
        path.push_back(node);
        if (path.size() > longest.size()) {
            longest = path;
        }

        for (int next : graph[node]) {
            if (!visited[next]) {
                dfs(graph, next, visited, path, longest);
            }
        }

        path.pop_back();
    }
    
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        if (n <= 0) {
            return vector<int>();
        }

        vector<vector<int>> graph(n);
        for (auto& e : edges) {
            graph[e.first].push_back(e.second);
            graph[e.second].push_back(e.first);
        }

        for (int i = 0, node = 0; i < 2; i++) {
            vector<char> visited(n, 0);
            vector<int> path, longest;
            dfs(graph, node, visited, path, longest);
            node = longest.back();

            if (i == 1) {
                int m = longest.size();
                if (m % 2 == 0) {
                    return vector<int>({longest[m/2-1], longest[m/2]});
                } else {
                    return vector<int>({longest[m/2]});
                }
            }
        }

        return vector<int>();
    }
};