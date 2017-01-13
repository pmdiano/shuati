class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> edges(n);
        vector<int> indegree(n, 0);

        for (auto& p : prerequisites) {
            edges[p.second].push_back(p.first);
            indegree[p.first]++;
        }

        stack<int> stk;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                stk.push(i);
            }
        }

        vector<int> order;
        order.reserve(n);
        while (!stk.empty()) {
            int node = stk.top();
            stk.pop();
            order.push_back(node);
            for (int neighbor : edges[node]) {
                if (--indegree[neighbor] == 0) {
                    stk.push(neighbor);
                }
            }
        }

        return order.size() == n ? order : vector<int>();
    }
};
