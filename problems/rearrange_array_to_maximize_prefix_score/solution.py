class Solution:
    def maxScore(self, nums: List[int]) -> int:
        nums.sort(reverse = True)
        c = 0
        cur = 0
        for i in nums:
            cur+=i
            if cur>0: c+=1
            else:   break
        return c