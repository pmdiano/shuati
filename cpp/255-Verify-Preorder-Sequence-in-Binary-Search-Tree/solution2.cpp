class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        int low = numeric_limits<int>::min();
        int index = -1;

        for (int num : preorder) {
            if (num < low) {
                return false;
            }

            while (index >= 0 && num > preorder[index]) {
                low = preorder[index--];
            }

            preorder[++index] = num;
        }

        return true;
    }
};
