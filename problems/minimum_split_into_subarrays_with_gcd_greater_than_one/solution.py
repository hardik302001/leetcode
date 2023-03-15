class Solution:
    def minimumSplits(self, nums: List[int]) -> int:
        res,cur = 0,1
        for num in nums:
            cur = math.gcd(cur,num)
            if cur==1:
                cur = num
                res+=1
        return res