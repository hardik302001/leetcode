class Solution:
    def smallestTrimmedNumbers(self, nums: List[str], queries: List[List[int]]) -> List[int]:
        d = {}
        n = len(nums)
        sz = len(nums[0])
        for le in range(1, sz+1):
            d[le] = []
            for i in range(n):
                y = int(nums[i][sz-le:])
                d[le].append([y, i])
        
        for i in d:
            d[i].sort()
        
        ans = []
        
        for k , t in queries:
            p = d[t][k-1][1]
            ans.append(p)
        return ans
            
            