class Solution {
    struct tuple {
        int start;
        int end;
        int sum;
    };

    tuple maxSubArrayRec(vector<int>& nums, int i, int j) {
        tuple result;
        if (i == j) {
            result.start = i;
            result.end = j;
            result.sum = nums[i];
            return result;
        }
        
        int mid = i + (j - i) / 2;
        tuple leftResult = maxSubArrayRec(nums, i, mid);
        tuple rightResult = maxSubArrayRec(nums, mid+1, j);
        tuple midResult = maxSubArrayMid(nums, i, j);
        
        if (leftResult.sum >= rightResult.sum && leftResult.sum >= midResult.sum)
            return leftResult;
        else if (rightResult.sum >= leftResult.sum && rightResult.sum >= midResult.sum)
            return rightResult;
        else
            return midResult;
    }
    
    tuple maxSubArrayMid(vector<int> &nums, int i, int j) {
        tuple result;
        int mid = i + (j - i) / 2;
        
        int leftSum = nums[mid];
        int left = mid;
        for (int k = mid - 1, sum = nums[mid]; k >= i; --k) {
            sum += nums[k];
            if (sum > leftSum) {
                leftSum = sum;
                left = k;
            }
        }
        
        int rightSum = nums[mid+1];
        int right = mid+1;
        for (int k = mid+2, sum = nums[mid+1]; k <= j; ++k) {
            sum += nums[k];
            if (sum >= rightSum) {
                rightSum = sum;
                right = k;
            }
        }
        
        result.start = left;
        result.end = right;
        result.sum = leftSum + rightSum;
        return result;
    }

public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty())
            return 0;

        tuple result = maxSubArrayRec(nums, 0, nums.size() - 1);
        return result.sum;
    }
};