class Solution:
    def executeInstructions(self, n: int, st: List[int], s: str) -> List[int]:
        ans = []
        
        for i in range(len(s)):
            p = s[i:]
            curx = st[0]
            cury = st[1]
            c = 0
            # print(p)
            for ch in p:
                if ch=='L':
                    cury = cury-1
                elif ch=='R':
                    cury = cury +1
                elif ch=='U':
                    curx = curx - 1
                else:
                    curx = curx + 1
                
                if curx<0 or cury<0 or curx==n or cury==n:
                    break
                else:
                    c = c +1
            ans.append(c)
        return ans