# Definition for singly-linked list.
# class ListNode
#     attr_accessor :val, :next
#     def initialize(val)
#         @val = val
#         @next = nil
#     end
# end

# @param {ListNode} head
# @param {Integer} k
# @return {ListNode}
def reverse_k_group(head, k)
    return head if head.nil? || k <= 1

    dummy = ListNode.new(0)
    dummy.next = head
    p, q = dummy, dummy

    while q
        k.times do
            q = q.next
            break if q.nil?
        end
        if q
            head = p.next
            reverse_between(p, q)
            p = q = head
        end
    end
    dummy.next
end

def reverse_between(head, tail)
    p, q, r = head, head.next, head.next
    while p != tail
        tmp = q.next
        q.next = p
        p = q
        q = tmp
    end
    head.next = p
    r.next = q
end
