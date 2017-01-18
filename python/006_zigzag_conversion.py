class Solution(object):
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        if numRows <= 1:
            return s

        rows = ["" for n in range(numRows)]
        i, dir = 0, -1
        for c in s:
            rows[i] += c
            if i == 0 or i == numRows - 1:
                dir = -dir
            i += dir

        return "".join(rows)
