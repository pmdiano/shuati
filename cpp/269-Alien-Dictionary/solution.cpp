class Solution {
public:
    string alienOrder(vector<string>& words) {
        const int R = 26;
        unordered_set<char> alphabet;
        vector<vector<int>> graph(R, vector<int>(R, 0));
        vector<int> indegree(R, 0);

        for (string& w : words) {
            for (char c : w) {
                alphabet.insert(c);
            }
        }

        for (int i = 1; i < words.size(); i++) {
            string& w1 = words[i-1];
            string& w2 = words[i];
            int j1 = 0, j2 = 0;
            while (j1 < w1.length() && j2 < w2.length() && w1[j1] == w2[j2]) {
                j1++, j2++;
            }
            if (w1[j1] && w2[j2] && !graph[w1[j1]-'a'][w2[j2]-'a']) {
                graph[w1[j1]-'a'][w2[j2]-'a'] = 1;
                indegree[w2[j2]-'a']++;
            }
        }

        string order;
        stack<int> stk;
        for (int i = 0; i < R; i++) {
            if (indegree[i] == 0 && alphabet.find('a'+i) != alphabet.end()) {
                stk.push(i);
            }
        }
        while (!stk.empty()) {
            int node = stk.top();
            stk.pop();
            order.push_back('a'+node);
            for (int neighbor = 0; neighbor < R; neighbor++) {
                if (graph[node][neighbor]) {
                    if (--indegree[neighbor] == 0) {
                        stk.push(neighbor);
                    }
                }
            }
        }

        return order.length() == alphabet.size() ? order : "";
    }
};