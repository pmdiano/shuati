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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) {
            return nullptr;
        }

        unordered_set<int> set;
        set.insert(head->val);

        ListNode* node = head->next;
        ListNode* prev = head;
        while (node) {
            if (set.find(node->val) == set.end()) {
                set.insert(node->val);
                node = node->next;
                prev = prev->next;
            } else {
                prev->next = node->next;
                delete node;
                node = prev->next;
            }
        }

        return head;
    }
};