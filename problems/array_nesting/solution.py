#dfs..find max element in each CC

class Solution:
    def arrayNesting(self, nums: List[int]) -> int:
        seen, res = [0] * len(nums), 0
        for i in nums:
            cnt = 0
            while not seen[i]:
                seen[i], cnt, i = 1, cnt + 1, nums[i]
            res = max(res, cnt)
        return res