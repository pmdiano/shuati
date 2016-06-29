/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        while (head) {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }

public:
    ListNode* plusOne(ListNode* head) {
        if (!head) {
            return nullptr;
        }

        head = reverse(head);

        ListNode* p = head;
        int carry = 0;
        if (++p->val == 10) {
            p->val = 0;
            carry = 1;
        }

        while (p->next && carry) {
            p = p->next;
            int sum = p->val + carry;
            p->val = sum % 10;
            carry = sum / 10;
        }

        if (carry) {
            p->next = new ListNode(carry);
        }

        return reverse(head);
    }
};