class Solution:
    def diStringMatch(self, s: str) -> List[int]:
        n = len(s)
        b = 0
        e = n
        ans = []
        for i in s:
            if i=='I':
                ans.append(b)
                b = b+1
                l = 0
            else:
                ans.append(e)
                e = e -1
                l = 1
        if l==0:
            ans.append(e)
        else:
            ans.append(b)
            
        return ans