# Definition for singly-linked list.
# class ListNode
#     attr_accessor :val, :next
#     def initialize(val)
#         @val = val
#         @next = nil
#     end
# end

# @param {ListNode} head
# @param {Integer} n
# @return {ListNode}
def remove_nth_from_end(head, n)
    dummy = ListNode.new(0)
    dummy.next = head

    p, q = dummy, dummy
    n.times do
        return head unless q.next
        q = q.next
    end

    while q.next
        q = q.next
        p = p.next
    end

    p.next = p.next.next
    return dummy.next
end
