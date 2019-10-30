class Solution:
    # 拓扑排序的应用
    def canFinish(self, numCourses: int, points: List[List[int]]) -> bool:
        degree = [0 for i in range(numCourses)]
        visited = 0
        for point in points:
            degree[point[1]]+=1
        while 0 in degree:
            for i in range(len(degree)):
                if degree[i] == 0:
                    degree[i] = -1
                    visited += 1
                    for j in points:
                        if j[0] == i:
                            degree[j[1]] -= 1
                    numCourses -= 1
                else:
                    continue
        return True if numCourses<visited else False
