# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
# 从前序和中序遍历序列构造二叉树
# 解题思路：通过递归，因为前序遍历的首节点便是根节点，在中序遍历中，根节点左边的便是左子树，右边的便是右子树，由此便可以层层递推下去
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        if not preorder:
            return None
        x = preorder.pop(0)
        node = TreeNode(x)
        i = inorder.index(x)
        node.left = self.buildTree(preorder[:i],inorder[:i])
        node.right = self.buildTree(preorder[i:],inorder[i+1:])
        return node
