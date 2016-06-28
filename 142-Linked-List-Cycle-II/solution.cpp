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
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next) {
            return nullptr;
        }

        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast && fast->next) {
            if (slow == fast) {
                break;
            }
            slow = slow->next;
            fast = fast->next->next;
        }

        if (slow != fast) {
            return nullptr;
        }

        slow = slow->next;
        while (slow != head) {
            slow = slow->next;
            head = head->next;
        }

        return head;
    }
};