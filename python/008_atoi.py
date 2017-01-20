class Solution(object):
    def myAtoi(self, str):
        """
        :type str: str
        :rtype: int
        """
        str = str.lstrip()
        ans = start = 0
        negative = False
        INT_MAX, INT_MIN = 2**31 - 1, -2**31

        if str.startswith('+'):
            start = 1
        if str.startswith('-'):
            start = 1
            negative = True

        for i in range(start, len(str)):
            if not str[i].isnumeric():
                break
            ans = 10 * ans + int(str[i])

        if ans >= INT_MAX:
            return INT_MIN if negative else INT_MAX
        return -ans if negative else ans
