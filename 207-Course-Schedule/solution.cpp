class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        if (numCourses <= 0) return true;
        int n = numCourses;
        vector<int> indegree(n, 0);
        vector<vector<int>> edge(n);

        for (auto& p : prerequisites) {
            edge[p.first].push_back(p.second);
            indegree[p.second]++;
        }

        stack<int> stk;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                stk.push(i);
            }
        }

        int count = 0;
        while (!stk.empty()) {
            int node = stk.top();
            stk.pop();
            count++;
            for (int x : edge[node]) {
                if (--indegree[x] == 0) {
                    stk.push(x);
                }
            }
        }

        return count == n;
    }
};