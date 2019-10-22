"""
# Definition for a Node.
class Node:
    def __init__(self, val, next, random):
        self.val = val
        self.next = next
        self.random = random
"""
class Solution:
    def copyRandomList(self, head: 'Node') -> 'Node':
        if not head:
            return head
        cur = head
        # 原地在每个节点后面复制链表节点
        while cur:
            node = Node(cur.val, cur.next, None)
            cur.next = node
            cur = cur.next.next
        # 复制random域
        cur = head
        while cur:
            cur.next.random = cur.random.next if cur.random != None else None
            cur = cur.next.next
        # 分离
        newhead = head.next
        cur = head
        while cur.next:
            temp = cur.next
            cur.next = cur.next.next
            cur = temp
        return newhead
