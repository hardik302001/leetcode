class Solution:
    def checkDistances(self, s: str, distance: List[int]) -> bool:
        d = {}
        beg = -1
        last = -1
        for i, v in enumerate(s):
            if v in d:
                d[v][1] = i
            else:
                d[v] = [i, -1]
        print(d)
        for i in d:
            x = distance[ord(i)-ord('a')]
            # print(i , x)
            if (d[i][1]-d[i][0]-1)!=x: return 0
        return 1
            