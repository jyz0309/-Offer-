/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(pHead==NULL) return NULL;
        nodeclone(pHead);
        connectRandom(pHead);
        return reconnect(pHead);

    }
    void nodeclone(RandomListNode *head){
        RandomListNode *p = head;
        while(p!=NULL)
        {
            RandomListNode *cur = new RandomListNode(p->label);
            cur->next = p->next;
            p->next = cur;
            p = cur->next;
        }
    }
    void connectRandom(RandomListNode *head){
        RandomListNode* p = head;
        while(p!=NULL){
            if(p->random) p->next->random = p->random->next;
            p = p->next->next;
        }
    }
    RandomListNode *reconnect(RandomListNode *head){
        RandomListNode *p = head;
        RandomListNode *result = head->next;
        while(p!=NULL){
            RandomListNode *cur = p->next;
            p->next = cur->next;
            p = p->next;
            if(p!=NULL) cur->next=p->next;
        }
        return result;
    }
};
