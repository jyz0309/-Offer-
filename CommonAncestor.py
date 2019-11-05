# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        cur = root
        path = [cur]
        while cur.val != p.val:
            if cur.val > p.val:
                cur = cur.left
            else:
                cur = cur.right
            path.append(cur)
        cur = root
        path2 = [cur]
        while cur.val != q.val:
            if cur.val > q.val:
                cur = cur.left
            else:
                cur = cur.right
            path2.append(cur)
        for i in range(len(path)-1,-1,-1):
            if path[i] in path2:
                return path[i]
