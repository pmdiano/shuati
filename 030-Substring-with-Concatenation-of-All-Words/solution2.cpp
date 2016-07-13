class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if (words.empty() || words[0].empty()) {
            return ans;
        }

        int m = words.size();
        int n = words[0].length();
        if (s.length() < m*n) {
            return ans;
        }

        unordered_map<string, int> hash;
        for (string& word : words) {
            hash[word]++;
        }

        for (int start = 0; start < n; start++) {
            int count = 0;
            unordered_map<string, int> slidingWindow;

            for (int i = start; i+n <= s.length(); i+=n) {
                string word = s.substr(i, n);
                
                if (hash.find(word) == hash.end()) {
                    count = 0;
                    slidingWindow.clear();
                } else {
                    count++;
                    slidingWindow[word]++;

                    while (hash[word] < slidingWindow[word]) {
                        string left = s.substr(i-(count-1)*n, n);
                        slidingWindow[left]--;
                        count--;
                    }

                    if (count == m) {
                        ans.push_back(i-(count-1)*n);
                    }
                }
            }
        }

        return ans;
    }
};