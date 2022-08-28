class Solution:
    def answerQueries(self, nums: List[int], queries: List[int]) -> List[int]:
        nums.sort()
        n = len(nums)
        pre = [0]*(n+1)
        for i in range(n):
            pre[i+1] = pre[i]+ nums[i]
        
        ans = []
        for q in queries:
            c = 0
            for i in range(1, n+1):
                if pre[i]>q:
                    break
                c+=1
            ans.append(c)
        return ans