class Solution {
    vector<int> original;
public:
    Solution(vector<int> nums) : original(nums) {
        
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return original;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> shuffle = original;
        for (int i = shuffle.size()-1, len = shuffle.size(); i >= 0; i--, len--) {
            int j = rand() % len;
            swap(shuffle[i], shuffle[j]);
        }
        return shuffle;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */