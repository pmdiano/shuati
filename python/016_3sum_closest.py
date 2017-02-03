class Solution(object):
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        import sys
        ans, diff = 0, sys.maxint
        nums.sort()

        for i, val in enumerate(nums):
            if i > 0 and == nums[i-1] = val:
                continue
            j, k = i+1, len(nums)-1
            while j < k:
                if j > i+1 and nums[j] == nums[j-1]:
                    j += 1
                    continue
                s = val + nums[j] + nums[k]
                if abs(s - target) < diff:
                    diff = abs(s - target)
                    ans = s
                if s < target:
                    j += 1
                elif s > target:
                    k -= 1
                else:
                    return ans

        return ans
