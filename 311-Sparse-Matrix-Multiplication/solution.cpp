class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        // key is row index, pair.first is col index, pair.second is value
        unordered_map<int, vector<pair<int, int>>> hash;
        for (int i = 0; i < B.size(); i++) {
            for (int j = 0; j < B[0].size(); j++) {
                if (B[i][j] != 0) {
                    hash[i].push_back(make_pair(j, B[i][j]));
                }
            }
        }

        vector<vector<int>> ans(A.size(), vector<int>(B[0].size(), 0));
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[0].size(); j++) {
                if (A[i][j] != 0) {
                    for (auto& p : hash[j]) {
                        ans[i][p.first] += A[i][j] * p.second;
                    }
                }
            }
        }

        return ans;
    }
};