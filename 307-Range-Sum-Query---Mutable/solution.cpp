class NumArray {
    struct CNode {
        int L, R;   // L <= R
        int sum;
        CNode *left, *right;
        CNode(int l, int r) : L(l), R(r), sum(0), left(nullptr), right(nullptr)
        {}
    };

    CNode* build(vector<int>& nums, int l, int r) {
        CNode *node = new CNode(l, r);
        if (l == r) {
            node->sum = nums[l];
        } else {
            int mid = (l+r)/2;
            node->left = build(nums, l, mid);
            node->right = build(nums, mid+1, r);
            node->sum = node->left->sum + node->right->sum;
        }
        return node;
    }

    int sumHelper(CNode* node, int i, int j) {
        if (i == node->L && j == node->R) {
            return node->sum;
        }

        int sum = 0;
        int mid = (node->L + node->R) / 2;
        if (i <= mid) {
            sum += sumHelper(node->left, i, min(mid, j));
        }
        if (j >= mid+1) {
            sum += sumHelper(node->right, max(mid+1, i), j);
        }

        return sum;
    }

    CNode* root;
    vector<int> vec;

public:
    NumArray(vector<int> &nums): root(nullptr) {
        if (!nums.empty()) {
            this->root = build(nums, 0, nums.size()-1);
            this->vec = nums;
        }
    }

    void update(int i, int val) {
        if (vec.empty() || i < 0 || i >= vec.size()) {
            return;
        }

        int diff = val - this->vec[i];
        this->vec[i] = val;

        CNode* node = this->root;
        while (node) {
            node->sum += diff;
            if (i <= (node->L + node->R) / 2) {
                node = node->left;
            } else {
                node = node->right;
            }
        }
    }

    int sumRange(int i, int j) {
        if (!root) {
            return 0;
        }

        i = max(i, 0);
        j = min(j, (int)vec.size() - 1);
        return sumHelper(this->root, i, j);
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);