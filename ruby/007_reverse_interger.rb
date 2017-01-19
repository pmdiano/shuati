# @param {Integer} x
# @return {Integer}
INT_MAX, INT_MIN = 2**31 - 1, -2**31
def reverse(x)
    y = 0
    negative = x < 0 ? true : false
    x = x.abs
    while x != 0
        y *= 10
        y += x % 10
        x /= 10
        return 0 if y > INT_MAX || y < INT_MIN
    end
    negative ? -y : y
end
