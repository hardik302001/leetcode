class Solution:
    def cellsInRange(self, s: str) -> List[str]:
        ans = []
        c1 = s[0]
        r1 = s[1]
        c2 = s[3]
        r2 = s[4]
        
        while c1<=c2:
            x = int(r1)
            while(x<=int(r2)):
                ans.append(str(c1) + str(x))
                x+=1
            
            c1 = chr(ord(c1) + 1)
        return ans