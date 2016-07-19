class Solution {
public:
    string convertToTitle(int n) {
        string ans;
        while (n) {
            ans.insert(0, 1, 'A' + (--n)%26);
            n /= 26;
        }
        return ans;
    }
};