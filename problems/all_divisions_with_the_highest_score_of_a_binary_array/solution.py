class Solution:
    def maxScoreIndices(self, nums: List[int]) -> List[int]:
        n = len(nums)
        l = [0]*(n+1)
        r = [0]*(n+1)
        
        for i in range(n):
            if nums[i]==0:
                l[i+1] = l[i] + 1
            else:
                l[i+1] = l[i]
        for i in range(n-1, -1 ,-1):
            if nums[i]==1:
                r[i] = r[i+1] + 1
            else:
                r[i] = r[i+1]
        # print(l)
        # print(r)
        ans = []
        m = 0
        for i in range(n+1):
            if l[i] + r[i] >m:
                ans = []
                ans.append(i)
                m = l[i] + r[i]
            elif l[i] + r[i] ==m:
                ans.append(i)
        return ans