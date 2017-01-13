/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if (!root) {
            return vector<vector<int>>();
        }

        map<int, vector<int>> hash;
        unordered_map<TreeNode*, int> posMap;
        queue<TreeNode*> q;

        posMap[root] = 0;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            int pos = posMap[node];
            hash[pos].push_back(node->val);
            if (node->left) {
                posMap[node->left] = pos-1;
                q.push(node->left);
            }
            if (node->right) {
                posMap[node->right] = pos+1;
                q.push(node->right);
            }
        }

        int i = 0;
        vector<vector<int>> result(hash.size());
        for (auto it = hash.cbegin(); it != hash.cend(); it++) {
            result[i++] = it->second;
        }

        return result;
    }
};
