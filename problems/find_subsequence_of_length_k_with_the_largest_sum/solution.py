class Solution:
    def maxSubsequence(self, nums: List[int], k: int) -> List[int]:
        p = []
        n = len(nums)
        for i in range(n):
            p.append([nums[i],i])
        p.sort(key = lambda x: (-x[0],x[1]))
        # print(p)
        q = []
        for i in range(k):
            q.append(p[i])
        q.sort(key = lambda x: x[1])
        
        ans = []
        for i in q:
            ans.append(i[0])
        return ans