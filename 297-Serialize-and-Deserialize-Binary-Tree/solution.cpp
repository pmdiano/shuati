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
    // My serialization here is preorder traversal with mark
    // 0 means a node has no children
    // 1 means a node only has left child
    // 2 means a node only has right child
    // 3 means a node has both left and right children
    static const char delimiter = ',';

public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        stack<TreeNode*> s;
        string result = "";

        while (root || !s.empty()) {
            if (root) {
                int mark = 0;
                mark |= (root->left != nullptr);
                mark |= ((root->right != nullptr) << 1);

                result += (to_string(root->val) + delimiter);
                result += (to_string(mark) + delimiter);

                if (root->right) {
                    s.push(root->right);
                }
                root = root->left;
            } else {
                root = s.top();
                s.pop();
            }
        }

        return result.substr(0, result.length() - 1);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "") {
            return nullptr;
        }

        stack<TreeNode*> s;
        TreeNode* dummy = new TreeNode(0);
        TreeNode* prev = dummy;

        data += delimiter;
        int pos = 0;

        while (data[pos]) {
            int i = pos;
            for (; data[i] != delimiter; i++);
            data[i] = '\0';
            TreeNode* node = new TreeNode(atoi(data.c_str() + pos));
            pos = i+1;

            if (prev) {
                prev->left = node;
            } else {
                s.top()->right = node;
                s.pop();
            }

            for (; data[i] != delimiter; i++);
            data[i] = '\0';
            int mark = atoi(data.c_str() + pos);
            pos = i+1;

            if (mark & 1) {
                prev = node;
            } else {
                prev = nullptr;
            }

            if (mark & 2) {
                s.push(node);
            }
        }

        TreeNode* root = dummy->left;
        delete dummy;
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
