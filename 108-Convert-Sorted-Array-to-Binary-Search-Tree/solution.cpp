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
    TreeNode* construct(int* nums, int start, int end) {
        if (start > end) {
            return nullptr;
        }

        int mid = start + (end - start) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = construct(nums, start, mid-1);
        root->right = construct(nums, mid+1, end);

        return root;
    }

public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty()) {
            return nullptr;
        }

        return construct(&nums[0], 0, nums.size() - 1);
    }
};