class Solution:
    def robotSim(self, commands: List[int], obstacles: List[List[int]]) -> int:
        ma = 0
        #       N    ,   W ,     S   ,    E
        dir = [[0,1], [-1, 0], [0, -1], [1, 0]]
        
        s = set()
        for obs in obstacles:
            s.add(str(obs[0]) + " "+ str(obs[1]))
        
        x = 0
        y = 0
        d = 0  # currently pointing to north
        
        for c in commands:
            if c==-2:
                d = (d + 1)%4
            elif c==-1:
                d = (d + 4 - 1)%4
            else:
                while c>0 and str(x + dir[d][0]) + " " + str(y + dir[d][1]) not in s:
                    x = x + dir[d][0]
                    y = y + dir[d][1]
                    c = c - 1
            # print(x,y)
            ma = max(ma, x*x + y*y)
                    
                
        
        return ma