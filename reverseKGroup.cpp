/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 /*
 解题思路：采用了栈来完成，遍历整个链表，并将结点逐个存入栈中，当栈中存放结点数量=k时，将栈中元素依次弹出，创建一个新的链表。
 值得注意的是，当最后剩下的数不足k个时，此时虽然剩下结点全都在栈中，但还是要将其逆序，弹入另外一个栈中，然后再弹出
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL||head->next==NULL||k==1) return head;
        ListNode* cur = head;
        int i = 1;
        while(cur->next!=NULL){
            i++;
            cur =cur->next;
        }
        if(i<k) return head;
        stack<ListNode*> s;
        ListNode* p = head;
        while(s.size()!=k){
            s.push(p);
            p = p->next;
        }
        ListNode* phead = s.top();
        s.pop();
        ListNode* p2 = phead;
        while(!s.empty()){
            p2->next = s.top();
            s.pop();
            p2 = p2->next;
            p2->next = NULL;
        }
        while(p!=NULL){
            s.push(p);
            p = p->next;
            if(s.size()==k){
                while(!s.empty()){
                    p2->next = s.top();
                    s.pop();
                    p2 = p2->next;
                    p2->next = NULL;
                }
            }
        }
        if(!s.empty()){
            stack<ListNode*> s2;
            while(!s.empty()){
                s2.push(s.top());
                s.pop();
            }
            while(!s2.empty()){
                p2->next = s2.top();
                s2.pop();
                p2 = p2->next;
            }
        }
        return phead;
    }
};
