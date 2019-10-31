class Solution:
    def findOrder(self, numCourses: int, points: List[List[int]]) -> List[int]:
        degree = [0 for i in range(numCourses)]
        visited = 0
        result = []
        for point in points:
            degree[point[0]]+=1
        while 0 in degree:
            for i in range(len(degree)):
                if degree[i] == 0:
                    degree[i] = -1
                    result.append(i)
                    visited += 1
                    for j in points:
                        if j[1] == i:
                            degree[j[0]] -= 1
                    numCourses -= 1
                else:
                    continue
        if numCourses>=visited:
            return []
        else:
            return result
