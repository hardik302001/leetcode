#  TC: O(n)

class Solution:
    def findPairs(self, nums: List[int], k: int) -> int:
        ans = 0
        d = {}
        for i in nums:
            if i in d:
                d[i]+=1
            else:
                d[i] = 1
                
        if k==0:
            for i in d:
                ans = ans + (d[i]>=2)
            return ans
        for i in d:
            if (i-k) in d and d[i-k]>0:
                ans = ans + 1
        return ans
    