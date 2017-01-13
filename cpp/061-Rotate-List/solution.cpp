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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || k <= 0) {
            return head;
        }

        ListNode* tail = head;
        int len = 1;
        while (tail->next) {
            tail = tail->next;
            len++;
        }

        k %= len;
        tail->next = head;

        for (int i = 0; i < len-k; i++) {
            tail = tail->next;
        }
        
        // Now tail is the new tail, and tail->next is the new head
        head = tail->next;
        tail->next = nullptr;
        return head;
    }
};