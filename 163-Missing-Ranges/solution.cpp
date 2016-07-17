class Solution {
    string range_to_string(int lower, int upper) {
        if (lower == upper) {
            return to_string(lower);
        }
        return to_string(lower) + "->" + to_string(upper);
    }
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> result;
        if (lower > upper) {
            return result;
        }

        for (int x : nums) {
            if (x < lower) continue;
            if (x > upper) {
                result.push_back(range_to_string(lower, upper));
                return result;
            }
            if (x == lower) {
                lower++;
                continue;
            }

            result.push_back(range_to_string(lower, x-1));
            lower = x+1;
        }

        if (lower <= upper) {
            result.push_back(range_to_string(lower, upper));
        }

        return result;
    }
};