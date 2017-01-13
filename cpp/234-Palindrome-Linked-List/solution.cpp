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
        if (!head || !head->next) {
            return head;
        }

        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

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
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) {
            return true;
        }

        ListNode* middle = findMiddle(head);
        ListNode* tail = reverse(middle->next);
        ListNode* next = middle->next;
        next->next = middle;

        ListNode* p = head;
        ListNode* q = tail;
        while (p != middle) {
            if (p->val != q->val) {
                break;
            }
            p = p->next;
            q = q->next;
        }
        bool ans = (p->val == q->val);

        next->next = nullptr;
        middle->next = reverse(tail);
        return ans;
    }
};
