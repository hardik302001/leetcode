class Solution:
    def destCity(self, paths: List[List[str]]) -> str:
        d = {}  #indegree = 0
        for path in paths:
            entry = path[0]
            exit = path[1]
            if entry  in d:
                d[entry]+=1
            else:
                d[entry] = 1
            if exit in d:
                d[exit]-=1
            else:
                d[exit] = -1
        for i in d:
            if d[i]==-1:
                return i
        