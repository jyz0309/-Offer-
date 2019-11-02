class Solution:
    # dfs的递归做法，憨批题目
    def cloneGraph(self, node: 'Node') -> 'Node':
        lookup = {}
        def dfs(node):
            if not node:
                return
            if node in lookup:
                return lookup[node]
            clone = Node(node.val,[])
            lookup[node] = clone
            for n in node.neighbors:
                clone.neighbors.append(dfs(n))
            return clone
        return dfs(node)
