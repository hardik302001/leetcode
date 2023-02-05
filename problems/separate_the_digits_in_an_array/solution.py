class Solution:
    def separateDigits(self, nums: List[int]) -> List[int]:
        ans = []
        for i in nums:
            p = []
            while i>0:
                x = i%10
                i = i//10
                p.append(x)
            p = p[::-1]
            ans.extend(p)
        return ans