class Solution(object):
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        m, n = len(s), len(p)
        dp = [[False for x in range(n+1)] for y in range(m+1)]
        dp[0][0] = True

        for i in range(m+1):
            for j in range(1, n+1):
                if i >= 1 and p[j-1] != '*':
                    dp[i][j] = dp[i-1][j-1] and \
                        (s[i-1] == p[j-1] or p[j-1] == '.')
                elif j >= 2 and p[j-1] == '*':
                    if dp[i][j-1] or dp[i][j-2]:
                        dp[i][j] = True
                    elif i > 0:
                        dp[i][j] = dp[i-1][j] and \
                            (s[i-1] == p[j-2] or p[j-2] == '.')
        return dp[m][n]
