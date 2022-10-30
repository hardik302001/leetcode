class Solution:
    def averageValue(self, nums: List[int]) -> int:
        s = 0
        c = 0
        for i in nums:
            if i%6==0:
                s += i
                c+=1
        if c==0: c=1
        return s//c