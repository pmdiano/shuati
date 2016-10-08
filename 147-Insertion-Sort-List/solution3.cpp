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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        while (head) {
            ListNode* next = head->next;
            ListNode* prev = dummy;
            while (prev->next && prev->next->val <= head->val) {
                prev = prev->next;
            }
            head->next = prev->next;
            prev->next = head;
            head = next;
        }
        head = dummy->next;
        delete dummy;
        return head;
    }
};