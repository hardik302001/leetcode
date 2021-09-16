class Solution:
    def smallestRangeI(self, nums: List[int], k: int) -> int:
        mi = min(nums)
        ma = max(nums)
        return max(0, min(ma - mi ,ma+ k-(mi -k) , ma-k-(mi + k) ))