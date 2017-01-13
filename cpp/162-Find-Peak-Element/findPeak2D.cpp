#include <vector>
#include <cstdio>
#include <iostream>
using namespace std;

class Solution {
    vector<int> findPeak(vector<vector<int> > &A, int r1, int r2, int c1, int c2) {
        printf("Finding in [%d..%d][%d..%d]\n", r1, r2, c1, c2);
        vector<int> index = findMaxOnFrame(A, r1, r2, c1, c2);
        printf("    Max on frame is %d at [%d][%d]\n", A[index[0]][index[1]], index[0], index[1]);
        
        int r = index[0];
        int c = index[1];
        int rmid = r1 + (r2 - r1) / 2;
        int cmid = c1 + (c2 - c1) / 2;

        if ((r == r1 || A[r][c] > A[r-1][c]) &&
            (r == r2 || A[r][c] > A[r+1][c]) &&
            (c == c1 || A[r][c] > A[r][c-1]) &&
            (c == c2 || A[r][c] > A[r][c+1])) {
            // Got it
            return index;
        } else if ((r == r1 && c1 < c && c < cmid) ||
                   (r == rmid && c1 < c && c < cmid && A[r-1][c] > A[r][c]) ||
                   (c == c1 && r1 < r && r < rmid) ||
                   (c == cmid && r1 < r && r < rmid && A[r][c-1] > A[r][c])) {
            // Continue searching in upper left quadrant
            return findPeak(A, r1+1, rmid-1, c1+1, cmid-1);
        } else if ((r == r1 && cmid < c && c < c2) ||
                   (r == rmid && cmid < c && c < c2 && A[r-1][c] > A[r][c]) ||
                   (c == c2 && r1 < r && r < rmid) ||
                   (c == cmid && r1 < r && r < rmid && A[r][c+1] > A[r][c])) {
            // Upper right quadrant
            return findPeak(A, r1+1, rmid-1, cmid+1, c2-1);
        } else if ((r == r2 && c1 < c && c < cmid) ||
                   (r == rmid && c1 < c && c < cmid && A[r+1][c] > A[r][c]) ||
                   (c == c1 && rmid < r && r < r2) ||
                   (c == cmid && rmid < r && r < r2 && A[r][c-1] > A[r][c])) {
            // Lower left quadrant
            return findPeak(A, rmid+1, r2-1, c1+1, cmid-1);
        } else {
            // Lower right quadrant
            return findPeak(A, rmid+1, r2-1, cmid+1, c2-1);
        }
    }
    
    vector<int> findMaxOnFrame(vector<vector<int> > &A, int r1, int r2, int c1, int c2) {
        int rmid = r1 + (r2 - r1) / 2;
        int cmid = c1 + (c2 - c1) / 2;
        int maxValue = A[r1][c1];
        
        vector<int> index = {r1, c1};
        vector<int> rows = {r1, rmid, r2};
        vector<int> cols = {c1, cmid, c2};
        
        for (int r : rows) {
            for (int c = c1; c <= c2; ++c) {
                if (A[r][c] > maxValue) {
                    maxValue = A[r][c];
                    index[0] = r;
                    index[1] = c;
                }
            }
        }
        
        for (int c : cols) {
            for (int r = r1; r <= r2; ++r) {
                if (A[r][c] > maxValue) {
                    maxValue = A[r][c];
                    index[0] = r;
                    index[1] = c;
                }
            }
        }
        
        return index;
    }

public:
    /**
     * @param A: An integer matrix
     * @return: The index of the peak
     */
    vector<int> findPeakII(vector<vector<int>> &A) {
        // write your code here
        if (A.empty() || A[0].empty())
            return vector<int>({0, 0});
        
        int m = A.size();
        int n = A[0].size();
        
        return findPeak(A, 0, m-1, 0, n-1);
    }
};

int main(void) {
    vector<vector<int>> A = {
        {1,2,3,4,5},
        {16,41,23,22,6},
        {15,17,24,21,7},
        {14,18,19,20,8},
        {13,12,11,10,9}
    };

    Solution sol;
    auto result = sol.findPeakII(A);
    cout << result[0] << " " << result[1] << endl;;

    return 0;
}

