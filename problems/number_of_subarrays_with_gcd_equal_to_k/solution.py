class Solution:
    def subarrayGCD(self, nums: List[int], k: int) -> int:
        c = 0
        for i in range(len(nums)):
            g = 0
            for j in range(i, len(nums)):
                g = gcd(g, nums[j])
                if g == k:
                    c += 1
        return c