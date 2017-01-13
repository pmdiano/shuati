/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    ListNode* findMiddle(ListNode* head) {
        ListNode* fast = head->next;
        ListNode* slow = head;

        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        return slow;
    }

    ListNode* merge(ListNode* head1, ListNode* head2) {
        ListNode* dummy = new ListNode(0);
        ListNode* p = dummy;

        while (head1 && head2) {
            if (head1->val < head2->val) {
                p->next = head1;
                head1 = head1->next;
            } else {
                p->next = head2;
                head2 = head2->next;
            }

            p = p->next;
        }

        if (head1) {
            p->next = head1;
        } else {
            p->next = head2;
        }

        p = dummy->next;
        delete dummy;
        return p;
    }

public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        ListNode* mid = findMiddle(head);
        ListNode* right = sortList(mid->next);
        mid->next = nullptr;
        ListNode* left = sortList(head);

        return merge(left, right);
    }
};
