/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* p = dummy;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                p->next = l1;
                p = p->next;
                l1 = l1->next;
            } else {
                p->next = l2;
                p = p->next;
                l2 = l2->next;
            }
        }

        if (l1) {
            p->next = l1;
        } else {
            p->next = l2;
        }

        p = dummy->next;
        delete dummy;
        return p;
    }

    ListNode* merge(vector<ListNode*>& lists, int start, int end) {
        if (start == end) {
            return lists[start];
        }

        int mid = start + (end - start) / 2;
        ListNode* list1 = merge(lists, start, mid);
        ListNode* list2 = merge(lists, mid+1, end);
        return mergeTwoLists(list1, list2);
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return nullptr;
        }

        return merge(lists, 0, lists.size() - 1);
    }
};