/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head) {
            return nullptr;
        }

        RandomListNode* p = head;
        while (p) {
            RandomListNode* next = p->next;
            p->next = new RandomListNode(p->label);
            p->next->next = next;
            p = next;
        }

        p = head;
        while (p) {
            if (p->random) {
                p->next->random = p->random->next; 
            }
            p = p->next->next;
        }

        RandomListNode* head2 = head->next;
        RandomListNode* q = head2;
        p = head;
        while (p->next->next) {
            p->next = p->next->next;
            q->next = q->next->next;
            p = p->next;
            q = q->next;
        }
        p->next = nullptr;
        q->next = nullptr;

        return head2;
    }
};