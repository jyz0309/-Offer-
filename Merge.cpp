/*
题目要求：输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。
解题思路：创建一个新的链表，然后从两个链表的表头开始遍历，每次取较小的值到新的链表中。
*/
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
 
        ListNode *p1,*p2,*pre1,*p3;
        pre1 = p1 = pHead1; p2 = pHead2;
        while(p1 && p2)
        {
            if(p1->val > p2->val)
            {
                pre1->next = p2;
                p3 = p2->next;
                p2->next = p1;
                p2 = p3;
            }
            pre1 = p1;
            p1 = p1->next;
        }
        if(p2)
            pre1->next = p2;
         
        return pHead1;
         
    }
};
