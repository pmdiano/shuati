# @param {String} s
# @return {String}
def longest_palindrome(s)
    ans = ""
    (0..s.length-1).each do |i|
        temp = expand(s, i, i)
        ans = temp if ans.length < temp.length
        
        temp = expand(s, i, i+1) if i < s.length-1
        ans = temp if ans.length < temp.length
    end
    ans
end

def expand(s, i, j)
    while i >= 0 && j < s.length && s[i] == s[j]
        i -= 1
        j += 1
    end
    s[i+1..j-1]
end
