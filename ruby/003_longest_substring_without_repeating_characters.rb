# @param {String} s
# @return {Integer}
def length_of_longest_substring(s)
    ans = i = j = 0
    counts = Array.new(256, 0)
    while i < s.length
        if counts[s[i].ord] == 0
            counts[s[i].ord] += 1
            i += 1
            ans = [ans, i - j].max
        else
            counts[s[j].ord] -= 1
            j += 1
        end
    end
    ans
end
