# @param {Integer} x
# @return {Boolean}
def is_palindrome(x)
    return false if x < 0

    y, d = x, 1
    while y >= 10
        y /= 10
        d *= 10
    end

    while d >= 10
        return false if x % 10 != x / d
        x %= d
        x /= 10
        d /= 100
    end
    true
end
