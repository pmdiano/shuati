/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
    UndirectedGraphNode* dfs(UndirectedGraphNode* node, unordered_map<UndirectedGraphNode*, UndirectedGraphNode*>& hash) {
        if (hash.find(node) != hash.end()) {
            return hash[node];
        }

        UndirectedGraphNode* clone = new UndirectedGraphNode(node->label);
        hash[node] = clone;

        clone->neighbors = vector<UndirectedGraphNode>(node->neighbors.size(), nullptr);
        for (int i = 0; i < node->neighbors.size(); i++) {
            clone->neighbors[i] = dfs(node->neighbors[i]);
        }

        return clone;
    }
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node) {
            return nullptr;
        }

        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> hash;
        return dfs(node, hash);
    }
};