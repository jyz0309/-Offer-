/*
题目要求：输入一个链表，按链表值从尾到头的顺序返回一个ArrayList。
解题思路：初始化一个vector，遍历链表，将链表结点中的值依次推入vector中，然后vector逆置。
时间复杂度：O(n)，空间复杂度：O(N)
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> res;
        ListNode *p = head;
        while(p != NULL){
            res.push_back(p->val);
            p = p->next;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
