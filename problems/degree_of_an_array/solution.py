class Solution:
    def findShortestSubArray(self, nums: List[int]) -> int:
        d = {}
        for i in nums:
            try:
                d[i]+=1
            except:
                d[i] = 1
        degree = max(d.values())
        pos = []
        for i in d:
            if d[i] == degree:
                pos.append(i)
        numrev = nums[::-1]
        m = 10000000
        print(pos)
        print(degree)
        for i in pos:
            f = nums.index(i)
            e = len(nums) - numrev.index(i) -1
            m = min(m,e-f+1)
            
        return m    