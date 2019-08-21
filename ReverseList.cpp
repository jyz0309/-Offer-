/*
题目要求：反转链表
解题思路：一开始使用栈，复杂化了问题- -。
*/
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if(!pHead) return nullptr;
        stack<int> stk;
        auto p = pHead;
        while(p){
            stk.push(p->val);
            p = p->next;
        }
        ListNode *head = new ListNode(stk.top());
        stk.pop();
        auto p1 = head;
        while(!stk.empty()){
            ListNode *cur = new ListNode(stk.top());
            p1->next = cur;
            p1 = p1->next;
            stk.pop();
        }
        return head;
    }
};
