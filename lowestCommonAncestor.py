# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # 思路：通过两个字典，一个字典记录二叉树每一个节点的父节点，另一个字典记录节点值和节点的对应关系
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        dic = {}
        node = {}
        self.reverse(root, node, dic)
        cur = p.val
        list1 = [cur]
        while cur in dic:
            cur = dic[cur]
            list1.append(cur)
        cur2 = q.val
        list2 = [cur2]
        while cur2 in dic:
            cur2 = dic[cur2]
            list2.append(cur2)
        for i in list1:
            if i in list2:
                return node[i]
        return root

    def reverse(self, root, node, dic):
        if not root:
            return 
        else:
            node[root.val] = root
            if root.left:
                dic[root.left.val] = root.val
            if root.right:
                dic[root.right.val] = root.val
            self.reverse(root.left, node, dic)
            self.reverse(root.right, node, dic)
