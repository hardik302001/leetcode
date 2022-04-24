class Solution:
    def intersection(self, nums: List[List[int]]) -> List[int]:
        n  = len(nums)
        d = Counter()
        for l in nums:
            for i in l:
                d[i]+=1
        
        ans = []
        for i in d:
            if d[i]==n:
                ans.append(i)
        ans.sort()
        return ans