class Solution {
    string time_to_str(int hour, int minute) {
        string hour_str = to_string(hour);
        string minute_str = to_string(minute);
        if (minute < 10) minute_str = "0" + minute_str;
        return hour_str + ":" + minute_str;
    }

    void helper(int num, int pos, vector<int> &bits, vector<string> &ans) {
        if (bits.size() - pos < num) {
            return;
        }

        int hour = 0, minute = 0;
        int d = 1, i = 0;
        for (; i < 4; i++) {
            if (bits[i]) {
                hour += d;
            }
            d <<= 1;
        }
        d = 1;
        for (; i < 10; i++) {
            if (bits[i]) {
                minute += d;
            }
            d <<= 1;
        }

        if (hour >= 12 || minute >= 60) {
            return;
        }

        if (num == 0) {
            ans.push_back(time_to_str(hour, minute));
            return;
        }

        for (int i = pos; i < bits.size(); i++) {
            bits[i] = 1;
            helper(num-1, i+1, bits, ans);
            bits[i] = 0;
        }
    }

public:
    vector<string> readBinaryWatch(int num) {
        vector<string> ans;
        vector<int> bits(10, 0);
        helper(num, 0, bits, ans);
        return ans;
    }
};