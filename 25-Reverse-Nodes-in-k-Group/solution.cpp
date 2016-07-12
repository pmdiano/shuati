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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k <= 1) {
            return head;
        }

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        head = dummy;
        ListNode* tail = head;

        for (;;) {
            int i = 0;
            while (i < k && tail) {
                i++;
                tail = tail->next;
            }

            if (!tail) {
                // We finished everything
                break;
            }

            ListNode* prev = head;
            ListNode* node = head->next;
            while (prev != tail) {
                ListNode* next = node->next;
                node->next = prev;
                prev = node;
                node = next;
            }
            ListNode* temp = head->next;
            head->next = prev;
            temp->next = node;

            head = temp;
            tail = temp;
        }

        head = dummy->next;
        delete dummy;
        return head;
    }
};