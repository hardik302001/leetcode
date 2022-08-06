class Solution:
    def countBadPairs(self, nums: List[int]) -> int:
        d = {}
        dd = Counter()
        n = len(nums)
        for i in range(n):
            x = nums[i]-i
            if x in d:
                d[x]+=1
            else:
                d[x] = 1
        
        
        zz = set()
        s = 0
        for i in d:
            s += d[i]
        
        res = 0
        p = -1
        ans = 0
        for i in d:
            res+=d[i]*(s-d[i])
        return res//2