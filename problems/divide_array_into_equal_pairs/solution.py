class Solution:
    def divideArray(self, nums: List[int]) -> bool:
        d = {}
        for i in nums:
            if i in d:
                d[i]+=1
            else:
                d[i] = 1
        for i in d:
            if d[i]&1:
                return False
        return True