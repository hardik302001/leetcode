class Solution:
    def maximumEvenSplit(self, tar: int) -> List[int]:
        if tar&1:
            return []
        t = tar
        ans = []
        ans.append(2)
        cur = 2
        t = t - cur
        
        if tar>2:
            while t>ans[-1]:
                ans.append(cur*2)
                t = t - cur*2
                cur = cur + 1
        if t!=0:
            ans = ans[::-1]
            x = 0
            while t>0:
                ans[x]+=2
                t -=2
                x +=1
        return ans