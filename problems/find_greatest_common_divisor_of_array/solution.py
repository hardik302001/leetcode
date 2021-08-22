import math
class Solution:
    def findGCD(self, nums: List[int]) -> int:
        mi = min(nums)
        ma = max(nums)
        return math.gcd(mi, ma)