class Solution {
    int mutate(int n) {
        int ans = 0;
        while (n) {
            ans += (n%10) * (n%10);
            n /= 10;
        }
        return ans;
    }

public:
    bool isHappy(int n) {
        unordered_set<int> visited;
        while (n != 1) {
            if (visited.find(n) != visited.end()) {
                return false;
            }
            visited.insert(n);
            n = mutate(n);
        }
        return true;
    }
};