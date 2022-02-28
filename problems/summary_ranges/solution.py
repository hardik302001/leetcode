class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        res = []
        if len(nums)==0:
            return nums
        nums.append("#")       # for last range 
        n = len(nums)
        prev = nums[0]
        s = nums[0]
        e = nums[0]
        for i in range(1 , n):
            if nums[i-1]+1==nums[i]:
                e = nums[i]
            else:
                if e==s:
                    res.append(str(s))
                else:
                    res.append(str(s) + "->" +str(e))
                
                s = nums[i]
                e = nums[i]
        return res