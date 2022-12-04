class Solution:
    def dividePlayers(self, ss: List[int]) -> int:
        n = len(ss)
        ss.sort()
        s = ss[0] + ss[-1]
        i = 0
        j = n-1
        ans = 0
        while i<j:
            cur = ss[i]+ ss[j]
            if cur!=s:
                return -1
            else:
                ans += ss[i]*ss[j]
            i+=1
            j-=1
        return ans
        
     