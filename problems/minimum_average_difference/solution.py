class Solution:
    def minimumAverageDifference(self, nums: List[int]) -> int:
        n = len(nums)
        p = [0]*(n+1)          # p[i] = sum of first i elements 
        for i in range(n):
            p[i+1] = p[i]+ nums[i]
        ans = 0
        ss = sum(nums)
        mi = 10000000000000
        for i in range(n):
            s1 = p[i+1]
            s2 = ss - s1
            
            s11 = (s1//(i+1))
            if i==(n-1):
                s22 = 0
            else:
                s22 = (s2//(n-i-1))
        
            
            dif = abs(s11 - s22)
            if dif < mi:
                # print(s11 , s22)
                mi = dif
                ans = i
        return ans