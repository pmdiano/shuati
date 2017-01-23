# @param {Integer[]} height
# @return {Integer}
def max_area(height)
    ans, i, j = 0, 0, height.length-1
    while i <= j
        size = (j-i) * [height[i], height[j]].min
        ans = [ans, size].max
        if height[i] < height[j]
            i += 1
        else
            j -= 1
        end
    end
    ans
end
