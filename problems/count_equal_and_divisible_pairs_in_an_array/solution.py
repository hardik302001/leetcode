class Solution:
    def countPairs(self, nums: List[int], k: int) -> int:
        n = len(nums)
        c = 0
        for i in range(n):
            for j in range(i+1, n):
                if nums[i]==nums[j] and (i*j)%k==0:
                    c =c  + 1
        return c