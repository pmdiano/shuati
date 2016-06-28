/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* p = dummy;
        int carry = 0;

        while (l1 && l2) {
            int sum = l1->val + l2->val + carry;
            p->next = new ListNode(sum % 10);
            carry = sum / 10;

            p = p->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        ListNode* l = l1 ? l1 : l2;
        while (l || carry) {
            int sum = carry;
            if (l) {
                sum += l->val;
                l = l->next;
            }
            p->next = new ListNode(sum % 10);
            carry = sum / 10;
            p = p->next;
        }

        p = dummy->next;
        delete dummy;
        return p;
    }
};
