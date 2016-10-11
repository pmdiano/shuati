class Solution {
public:
    string removeKdigits(string num, int k) {
        if (k <= 0) {
            return num;
        }
        string ans;
        int i = 0;
        while (i < num.size()) {
            if (ans.empty() || num[i] >= ans.back()) {
                ans.push_back(num[i++]);
            } else {
                while (k > 0 && !ans.empty() && num[i] < ans.back()) {
                    ans.pop_back();
                    k--;
                }
                if (k == 0) {
                    break;
                }
            }
        }
        
        if (i < num.size()) {
            ans += num.substr(i);
        }
        if (k > 0) {
            k = min(k, (int)ans.size());
            ans = ans.substr(0, ans.size() - k);
        }

        i = 0;
        while (i < ans.size() && ans[i] == '0') {
            i++;
        }
        ans = ans.substr(i);
        if (ans.empty()) {
            return "0";
        }
        return ans;
    }
};