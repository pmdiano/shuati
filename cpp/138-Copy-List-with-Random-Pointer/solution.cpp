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

        RandomListNode* head2 = new RandomListNode(head->label);
        unordered_map<RandomListNode*, RandomListNode*> map;
        map[head] = head2;

        RandomListNode* p = head;
        RandomListNode* q = head2;
        while (p->next) {
            q->next = new RandomListNode(p->next->label);
            map[p->next] = q->next;
            p = p->next;
            q = q->next;
        }

        p = head;
        q = head2;
        while (p) {
            if (p->random) {
                q->random = map[p->random];
            }
            p = p->next;
            q = q->next;
        }

        return head2;
    }
};