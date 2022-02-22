class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        d = Counter()
        n = len(nums)
        for i in nums:
            d[i]+=1
        ans = []
        for i in d:
            if d[i]>(n//3):
                ans.append(i)
        
        return ans