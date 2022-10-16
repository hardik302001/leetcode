class Solution:
    def countDistinctIntegers(self, nums: List[int]) -> int:
        ss = set(nums)
        ans = len(ss)
        for i in nums:
            r = str(i)[::-1]
            r = int(r)
            if r not in ss:
                ans+=1
                ss.add(r)
        return ans