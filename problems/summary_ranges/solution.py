class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        res = []
        if len(nums)==0:
            return nums
        
        n = len(nums)
        s = nums[0]
        for i in range(1,n):
            if nums[i]==(nums[i-1]+1):
                continue
            else:
                if s==nums[i-1]:
                    res.append(str(s))
                    s = nums[i]
                else:
                    e = nums[i-1]
                    ss = str(s) + "->" + str(e)
                    res.append(str(ss))
                    s = nums[i]
        if s==nums[-1]:
            res.append(str(s))
        else:
            e = nums[-1]
            ss = str(s) + "->" + str(e)
            res.append(str(ss))
        return res