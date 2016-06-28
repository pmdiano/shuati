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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        ListNode* prev = dummy;
        dummy->next = head;
        
        while (head && head->next) {
            ListNode* next = head->next->next;
            head->next->next = head;
            prev->next = head->next;
            head->next = next;

            prev = head;
            head = head->next;
        }

        head = dummy->next;
        delete dummy;
        return head;
    }
};