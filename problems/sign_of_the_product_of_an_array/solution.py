class Solution:
    def arraySign(self, nums: List[int]) -> int:
        z = 0
        n = 0
        for i in nums:
            if i<0:
                n = n +1
            if i==0:
                z = 1
                break
        if z==1:
            return 0
        elif n%2==0:
            return 1
        else:
            return -1