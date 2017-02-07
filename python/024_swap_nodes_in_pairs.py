# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if not head:
            return head

        dummy = ListNode(0)
        dummy.next = head
        p = dummy
        q = p.next

        while q and q.next:
            t = q.next.next
            p.next = q.next
            q.next.next = q
            q.next = t
            p = q
            q = t

        return dummy.next
