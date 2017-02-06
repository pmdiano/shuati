# Definition for singly-linked list.
# class ListNode
#     attr_accessor :val, :next
#     def initialize(val)
#         @val = val
#         @next = nil
#     end
# end

# @param {ListNode} l1
# @param {ListNode} l2
# @return {ListNode}
def merge_two_lists(l1, l2)
    dummy = ListNode.new(0)
    node = dummy
    while l1 && l2
        if l1.val < l2.val
            node.next = l1
            l1 = l1.next
        else
            node.next = l2
            l2 = l2.next
        end
        node = node.next
    end
    node.next = l1 ? l1 : l2
    dummy.next
end
