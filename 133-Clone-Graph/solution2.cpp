/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node) {
            return nullptr;
        }

        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> hash;
        vector<UndirectedGraphNode*> nodes;
        queue<UndirectedGraphNode*> q;
        q.push(node);
        nodes.push_back(node);
        hash[node] = new UndirectedGraphNode(node->label);

        while (!q.empty()) {
            UndirectedGraphNode* head = q.front();
            q.pop();

            for (UndirectedGraphNode* neighbor : head->neighbors) {
                if (hash.find(neighbor) == hash.end()) {
                    q.push(neighbor);
                    nodes.push_back(neighbor);
                    hash[neighbor] = new UndirectedGraphNode(neighbor->label);
                }
            }
        }

        for (UndirectedGraphNode* n : nodes) {
            for (UndirectedGraphNode* neighbor : n->neighbors) {
                hash[n]->neighbors.push_back(hash[neighbor]);
            }
        }

        return hash[node];
    }
};