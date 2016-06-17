/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // This one uses one byte as flag
    // Divide and Conquer

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root)
            return string("");

        char data[1 + sizeof(int)] = {0};
        if (root->left)
            data[0] |= 1;
        if (root->right)
            data[0] |= 2;
        int* addr = reinterpret_cast<int*>(&data[1]);
        *addr = root->val;

        string leftStr = serialize(root->left);
        string rightStr = serialize(root->right);
        string result(sizeof(data) + leftStr.size() + rightStr.size(), 0);

        char* ptr = &result[0];
        memcpy(ptr, data, sizeof(data));
        memcpy(ptr + sizeof(data), leftStr.c_str(), leftStr.size());
        memcpy(ptr + sizeof(data) + leftStr.size(), rightStr.c_str(), rightStr.size());
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.size() == 0)
            return nullptr;

        int treeSize = 0;
        return deserialize(&data[0], &treeSize);
    }
    
    TreeNode* deserialize(char* data, int* treeSize) {
        bool hasLeft = (data[0] & 1);
        bool hasRight = (data[0] & 2);
        int leftSize = 0;
        int rightSize = 0;

        TreeNode* root = new TreeNode(*(reinterpret_cast<int*>(&data[1])));
        
        data += (1 + sizeof(int));
        if (hasLeft)
            root->left = deserialize(data, &leftSize);
        if (hasRight)
            root->right = deserialize(data + leftSize, &rightSize);
        *treeSize = (1 + sizeof(int)) + leftSize + rightSize;

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));