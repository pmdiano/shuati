class Solution(object):
    def fourSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        def nsum(nums, target, n, result, results):
            if len(nums) < n or n < 2 or target < nums[0]*n or target > nums[-1]*n:
                return
            if n == 2:
                l, r = 0, len(nums)-1
                while l < r:
                    if l > 0 and nums[l] == nums[l-1]:
                        l += 1
                        continue
                    s = nums[l] + nums[r]
                    if s < target:
                        l += 1
                    elif s > target:
                        r -= 1
                    else:
                        results.append(result + [nums[l], nums[r]])
                        l += 1
            else:
                for i in range(len(nums)-n+1):
                    if i > 0 and nums[i] == nums[i-1]:
                        continue
                    nsum(nums[i+1:], target-nums[i], n-1, result+[nums[i]], results)

        results = []
        nsum(sorted(nums), target, 4, [], results)
        return results
                        
