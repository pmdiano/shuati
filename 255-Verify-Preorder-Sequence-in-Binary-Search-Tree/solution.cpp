class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        int low = numeric_limits<int>::min();
        stack<int> path;

        for (int num : preorder) {
            if (num < low) {
                return false;
            }

            while (!path.empty() && num > path.top()) {
                low = path.top();
                path.pop();
            }

            path.push(num);
        }

        return true;
    }
};
