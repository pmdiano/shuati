class Solution {
    void dfs(unordered_map<string, multiset<string>> &graph, string city, vector<string> &res) {
        while (graph[city].size()) {
            string next = *graph[city].begin();
            graph[city].erase(graph[city].begin());
            dfs(graph, next, res);
        }
        res.push_back(city);
    }

public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        unordered_map<string, multiset<string>> graph;
        for (auto& p : tickets) {
            graph[p.first].insert(p.second);
        }

        vector<string> res;
        dfs(graph, "JFK", res);
        return vector<string>(res.rbegin(), res.rend());
    }
};