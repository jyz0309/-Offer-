class Solution:
    def robot(self, command: str, obstacles: List[List[int]], x: int, y: int) -> bool:
        if len(obstacles) == 0 or (x == 0 and y == 0):
             return True
        if command == '':
            return False
        cor_x = 0
        cor_y = 0
        i = 0
        dic = {}
        for point in obstacles:
            if point[0] not in dic.keys():
                dic[point[0]] = [point[1]]
            else:
                dic[point[0]].append(point[1])
        while cor_x!=x or cor_y!=y:
            if command[i%len(command)] == 'U':
                cor_y += 1
            elif command[i%len(command)] == 'R':
                cor_x += 1
            if cor_x>x or cor_y>y:
                return False
            if cor_x in dic.keys() and cor_y in dic[cor_x]: 
                return False
            i+=1
        return True
