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

        int carry = 1;
        ListNode *p = head, *prev = nullptr;

        while (p && carry) {
            int sum = p->val + carry;
            p->val = sum % 10;
            carry = sum / 10;

            prev = p;
            p = p->next;
        }

        if (carry) {
            prev->next = new ListNode(carry);
        }

        return reverse(head);
    }
};