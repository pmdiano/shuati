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
    void serialize(TreeNode* root, ostringstream& os) {
        if (root) {
            os << root->val << " ";
            serialize(root->left, os);
            serialize(root->right, os);
        } else {
            os << "# ";
        }
    }

    TreeNode* deserialize(istringstream& is) {
        string val;
        is >> val;
        if (val == "#") {
            return nullptr;
        }

        TreeNode* root = new TreeNode(stoi(val));
        root->left = deserialize(is);
        root->right = deserialize(is);
        return root;
    }

public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        serialize(root, out);
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return deserialize(in);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));