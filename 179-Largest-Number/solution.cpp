class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> strs(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            strs[i] = to_string(nums[i]);
        }

        sort(strs.begin(), strs.end(), [](const string& a, const string& b) -> bool {
            return a+b > b+a;
        });

        if (strs[0][0] == '0') {
            return "0";
        }

        string ans;
        for (const string& s : strs) {
            ans += s;
        }
        return ans;
    }
};