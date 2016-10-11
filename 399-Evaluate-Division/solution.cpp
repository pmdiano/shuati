class Solution {
    bool dfs(unordered_map<string, unordered_map<string, double>> &graph, unordered_set<string> &used, string src, string dst, double &res) {
        if (src == dst) {
            return true;
        }
        for (auto it = graph[src].begin(); it != graph[src].end(); it++) {
            string next = it->first;
            if (used.count(next)) {
                continue;
            }
            used.insert(next);
            double tmp = res;
            res *= it->second;
            if (dfs(graph, used, next, dst, res)) {
                return true;
            }
            res = tmp;
            used.erase(next);
        }
        return false;
    }

public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> query) {
        unordered_map<string, unordered_map<string, double>> graph;
        unordered_set<string> mySet;
        for (int i = 0; i < equations.size(); i++) {
            graph[equations[i].first][equations[i].second] = values[i];
            if (values[i] != 0.0) {
                graph[equations[i].second][equations[i].first] = 1.0 / values[i];
            }
            mySet.insert(equations[i].first);
            mySet.insert(equations[i].second);
        }

        vector<double> res(query.size(), -1.0);
        for (int i = 0; i < query.size(); i++) {
            if (!mySet.count(query[i].first) || !mySet.count(query[i].second)) {
                res[i] = -1.0;
            } else if (query[i].first == query[i].second) {
                res[i] = 1.0;
            } else {
                unordered_set<string> used;
                double path = 1.0;
                if (dfs(graph, used, query[i].first, query[i].second, path)) {
                    res[i] = path;
                } else {
                    res[i] = -1.0;
                }
            }
        }

        return res;
    }
};