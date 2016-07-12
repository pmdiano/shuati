class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i=0, n = nums.size();
        vector<int>& A = nums;

        while(i<n) {
            if(A[i]!=i+1 && A[i]>0 && A[i]<=n && A[i]!=A[A[i]-1])
                swap(A[i],A[A[i]-1]);
            else
                i++;
        }
        for(int i=0; i<n; i++) {
            if(A[i]!=i+1) return i+1;
        }
        return n+1;
    }
};