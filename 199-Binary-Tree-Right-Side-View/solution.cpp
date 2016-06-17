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
    void dfs(TreeNode* root, unordered_map<int, int>& depthToValMap, int depth) {
        if (!root) {
            return;
        }

        depthToValMap[depth] = root->val;
        dfs(root->left, depthToValMap, depth+1);
        dfs(root->right, depthToValMap, depth+1);
    }

public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        unordered_map<int, int> depthToValMap;

        dfs(root, depthToValMap, 0);
        int depth = 0;
        while (depthToValMap.find(depth) != depthToValMap.end()) {
            result.push_back(depthToValMap[depth]);
            depth++;
        }

        return result;
    }
};