class Solution:
    def singleNumber(self, nums: List[int]) -> List[int]:
        d ={}
        for i in nums:
            if i in d:
                d[i]+=1
            else:
                d[i] = 1
        ans = []
        for i in d:
            if d[i]==1:
                ans.append(i)
        return ans