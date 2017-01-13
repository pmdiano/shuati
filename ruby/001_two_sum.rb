# @param {Integer[]} nums
# @param {Integer} target
# @return {Integer[]}
def two_sum(nums, target)
    hash = {}
    nums.each_with_index do |num, index|
        if hash.has_key?(target - num)
            return [hash[target-num], index]
        end
        hash[num] = index
    end
    []
end
