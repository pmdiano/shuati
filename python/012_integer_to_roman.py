class Solution(object):
    def intToRoman(self, num):
        """
        :type num: int
        :rtype: str
        """
        str, i = "", 0
        nums = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1]
        words = ["M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX",
                 "V", "IV", "I"]
        while num != 0:
            times, num = divmod(num, nums[i])
            str += words[i] * times
            i += 1
        return str
