class Solution:
    def countNicePairs(self, nums: List[int]) -> int:
        d ={}
        for i in nums:
            x = i - int(str(i)[::-1])
            if x in d:
                d[x]+=1
            else:
                d[x] =1 
        ans = 0
        for i in d:
            if d[i]>1:
                ans = ans + d[i]*(d[i]-1)//2
                ans = ans %1000000007
        return ans%1000000007