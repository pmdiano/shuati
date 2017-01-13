/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    int getLen(ListNode* head) {
        int len = 0;
        while (head) {
            len++;
            head = head->next;
        }
        return len;
    }

    void quickSort(ListNode* prev, int len) {
        if (len <= 1) {
            return;
        }

        int leftLen = 0;
        pair<ListNode*, int> right = partition(prev, len, &leftLen);
        quickSort(prev, leftLen);
        quickSort(right.first, right.second);
    }

    pair<ListNode*, int> partition(ListNode* prev, int len, int* leftLen) {
        ListNode* right = new ListNode(0);
        ListNode* mid = new ListNode(0);
        ListNode* p = prev;
        ListNode* q = right;
        ListNode* r = mid;

        ListNode* node = prev->next;
        int pivot = node->val;
        int leftL = 0;
        int rightL = 0;

        while (len--) {
            if (node->val < pivot) {
                p->next = node;
                p = p->next;
                leftL++;
            } else if (node->val == pivot) {
                r->next = node;
                r = r->next;
            } else {
                q->next = node;
                q = q->next;
                rightL++;
            }
            node = node->next;
        }

        p->next = mid->next;
        q->next = node;
        r->next = right->next;
        *leftLen = leftL;

        delete mid;
        delete right;
        return make_pair(r, rightL);
    }

public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        ListNode* prev = new ListNode(0);
        prev->next = head;

        quickSort(prev, getLen(head));

        head = prev->next;
        delete prev;
        return head;
    }
};
