# @param {Integer[]} nums
# @return {Integer[][]}
def three_sum(nums)
    ans = []
    nums.sort!
    nums.length.times do |i|
        next if i > 0 && nums[i] == nums[i-1]
        j, k = i+1, nums.length-1
        while j < k
            if j > i+1 && nums[j] == nums[j-1]
                j += 1
            elsif nums[i] + nums[j] + nums[k] > 0
                k -= 1
            elsif nums[i] + nums[j] + nums[k] < 0
                j += 1
            else
                ans.push([nums[i], nums[j], nums[k]])
                j += 1
                k -= 1
            end
        end
    end
    ans
end
