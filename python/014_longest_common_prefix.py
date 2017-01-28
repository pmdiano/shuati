class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        if not strs:
            return ""

        l = min([len(str) for str in strs])
        prefix = strs[0][:l]

        for i in range(0, l):
            for str in strs:
                if str[i] != prefix[i]:
                    return prefix[:i]
        return prefix
