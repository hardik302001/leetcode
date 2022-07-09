class Solution:
    def prefixesDivBy5(self, nums: List[int]) -> List[bool]:
        c = 0
        ans = []
        for i in nums:
            c = 2*c + i
            if c%5==0:  ans.append(True)
            else:       ans.append(False)
        return ans