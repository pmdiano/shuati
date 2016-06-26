/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


class Solution {
    class ListNodeCompare {
    public:
        bool operator()(ListNode*& lhs, ListNode*& rhs) {
            return lhs->val >= rhs->val;
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return nullptr;
        }

        ListNode* dummy = new ListNode(0);
        ListNode* p = dummy;

        priority_queue<ListNode*, vector<ListNode*>, ListNodeCompare> heap;
        for (auto head : lists) {
            if (head) {
                heap.push(head);
            }
        }

        while (!heap.empty()) {
            ListNode* node = heap.top();
            heap.pop();

            p->next = node;
            p = p->next;

            if (node->next) {
                heap.push(node->next);
            }
        }

        p = dummy->next;
        delete dummy;
        return p;
    }
};