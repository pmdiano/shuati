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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty()) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(nums[(nums.size()-1)/2]);
        queue<TreeNode*> nodes;
        queue<int> leftIdx;
        queue<int> rightIdx;

        nodes.push(root);
        leftIdx.push(0);
        rightIdx.push(nums.size() - 1);

        while (!nodes.empty()) {
            TreeNode* node = nodes.front(); nodes.pop();
            int left = leftIdx.front(); leftIdx.pop();
            int right = rightIdx.front(); rightIdx.pop();
            int mid = left + (right - left) / 2;
            
            if (left <= mid-1) {
                TreeNode* leftChild = new TreeNode(nums[left + (mid-1-left) / 2]);
                node->left = leftChild;
                nodes.push(leftChild);
                leftIdx.push(left);
                rightIdx.push(mid-1);
            }
            
            if (mid+1 <= right) {
                TreeNode* rightChild = new TreeNode(nums[mid+1 + (right-mid-1) / 2]);
                node->right = rightChild;
                nodes.push(rightChild);
                leftIdx.push(mid+1);
                rightIdx.push(right);
            }
        }

        return root;
    }
};