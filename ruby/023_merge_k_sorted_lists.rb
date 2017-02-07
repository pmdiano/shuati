# Definition for singly-linked list.
# class ListNode
#     attr_accessor :val, :next
#     def initialize(val)
#         @val = val
#         @next = nil
#     end
# end

# @param {ListNode[]} lists
# @return {ListNode}
def merge_k_lists(lists)
    return nil if lists.empty?
    return lists[0] if lists.length == 1

    n = lists.length
    merge_two_lists(merge_k_lists(lists[0...n/2]),
                    merge_k_lists(lists[n/2...n]))
end

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
