class Solution:
    def nearestValidPoint(self, x: int, y: int, points: List[List[int]]) -> int:
        d = {}
        c = 0
        for a,b in points:
            if a==x:
                if abs(b-y) not in d:
                    d[abs(b-y)] = c
            elif b==y:
                if abs(a-x) not in d:
                    d[abs(a-x)] = c
            c = c +1
        print(d)
        m = 1000000
        for i in d:
            if m>i:
                m = i
                ans = d[i]
            print(m,ans)
        
        if m==1000000:
            return -1
        else:
            return (ans)
            
                    
                