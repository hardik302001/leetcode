class Solution(object):
    def findRelativeRanks(self, nums):
        """
        :type nums: List[int]
        :rtype: List[str]
        """
        score2pos = {}
        for i, num in enumerate(nums):
            score2pos[num] = i
        sorted_nums = sorted(nums)
        res = ["" for _ in range(len(nums))]
        for i, num in enumerate(sorted_nums[::-1]):
            if i == 0:
                res[score2pos[num]] = "Gold Medal"
            elif i == 1:
                res[score2pos[num]] = "Silver Medal"
            elif i == 2:
                res[score2pos[num]] = "Bronze Medal"
            else:
                res[score2pos[num]] = str(i + 1)
        return res