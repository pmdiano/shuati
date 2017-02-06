class Solution(object):
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        def dfs(l, r, str, res):
            if len(str) == 2 * n:
                res.append(str)
            else:
                if l < n:
                    dfs(l+1, r, str+'(', res)
                if r < l:
                    dfs(l, r+1, str+')', res)

        res = []
        str = ''
        dfs(0, 0, str, res)
        return res
