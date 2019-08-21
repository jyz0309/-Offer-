/*
题目要求：输入一个链表，输出该链表中倒数第k个结点。
解题思路：采用了快慢指针的思想，先让快指针走K步，然后让慢指针和快指针一起移动，当快指针到达末尾时慢指针所处位置就是倒数第k个位置
时间复杂度：O(N),空间复杂度O(1)
*/
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        auto p = pListHead;
        for(int i=1;i<=k;i++){
            if(!p) return nullptr;
            p = p->next;
        }
        while(p!=NULL){
            p = p->next;
            pListHead = pListHead->next;
        }
        return pListHead;
    }
};
