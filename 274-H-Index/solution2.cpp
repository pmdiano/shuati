class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> hash(n + 1, 0);
        for (int x : citations) {
            hash[x > n ? n : x]++;
        }

        int sum = 0;
        for (int i = n; i >= 0; i--) {
            sum += hash[i];
            if (sum >= i) {
                return i;
            }
        }

        return 0;
    }
};