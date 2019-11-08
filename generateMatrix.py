class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        mat = [[0 for i in range(n)] for j in range(n)]
        def helper(start,y,x):
            cur_x = n-1
            cur_y = n-1
            if (y>=n or x>=n) or mat[y][x] != 0:
                return
            else:
                for i in range(x, n):
                    if mat[y][i] != 0:
                        cur_x = i-1
                        break
                    else:
                        mat[y][i] = start
                        start += 1
                for j in range(y+1,n):
                    if mat[j][cur_x] !=0:
                        cur_y = j-1
                        break
                    else:
                        mat[j][cur_x] = start
                        start+=1
                for _i in range(cur_x-1,x-1,-1):
                    if mat[cur_y][_i] != 0:
                        break
                    else:
                        mat[cur_y][_i] = start
                        start += 1
                for _j in range(cur_y-1,y,-1):
                    if mat[_j][x] != 0:
                        break
                    else:
                        mat[_j][x] = start
                        start += 1
                helper(start,y+1,x+1)
        helper(1,0,0)
        return mat

