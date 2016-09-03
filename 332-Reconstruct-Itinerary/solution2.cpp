class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        vector<string> res;
        stack<string> stk;
        unordered_map<string, multiset<string>> graph;
        for (auto a : tickets) {
            graph[a.first].insert(a.second);
        }

        string cur = "JFK";
        for (int i = 0; i < tickets.size(); i++) {
            while (graph.find(cur) == graph.end() || graph[cur].empty()) {
                stk.push(cur);
                cur = res.back();
                res.pop_back();
            }
            res.push_back(cur);
            string t = cur;
            cur = *graph[cur].begin();
            graph[t].erase(graph[t].begin());
        }

        res.push_back(cur);
        while (!stk.empty()) {
            res.push_back(stk.top());
            stk.pop();
        }
        return res;
    }
};