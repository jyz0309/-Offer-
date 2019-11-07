class Solution:
    def generateTrees(self, n: int) -> List[TreeNode]:

        def generate(start, end):
            if start>end:
                return [None]
            all_trees = []
            for i in range(start,end+1):
                left = generate(start,i-1)
                right = generate(i+1,end)
                for l in left:
                    for r in right:
                        cur = TreeNode(i)
                        cur.left = l
                        cur.right = r
                        all_trees.append(cur)
            return all_trees
        return generate(1, n) if n else []
