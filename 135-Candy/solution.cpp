class Solution {
public:
    int candy(vector<int>& ratings) {
        if (ratings.empty()) {
            return 0;
        }
        vector<int> forward(ratings.size(), 1);
        vector<int> backward(ratings.size(), 1);

        for (int i = 1; i < ratings.size(); i++) {
            if (ratings[i] > ratings[i-1]) {
                forward[i] = forward[i-1] + 1;
            }
        }
        for (int i = ratings.size()-2; i >= 0; i--) {
            if (ratings[i] > ratings[i+1]) {
                backward[i] = backward[i+1] + 1;
            }
        }

        int candy = 0;
        for (int i = 0; i < ratings.size(); i++) {
            candy += max(forward[i], backward[i]);
        }
        return candy;
    }
};