# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        if not l1 and not l2:
            return None

        root = n = ListNode(0)
        a = 0

        while l1 or l2 or a > 0:
            if l1:
                a += l1.val
                l1 = l1.next
            if l2:
                a += l2.val
                l2 = l2.next

            n.next = n = ListNode(a % 10)
            a = a / 10

        return root.next
