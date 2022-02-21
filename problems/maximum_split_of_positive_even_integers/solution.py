class Solution:
    def maximumEvenSplit(self, target: int) -> List[int]:
        if target&1:return []
        
        cur = 2
        ans = []
        s = 0
        while s<target:
            ans.append(cur)
            s += cur
            cur += 2
        
        if s==target: return ans
        
        # print(ans)
        s = s - ans.pop()
        extra = target - s
        ans[-1]+=extra
        return ans
        