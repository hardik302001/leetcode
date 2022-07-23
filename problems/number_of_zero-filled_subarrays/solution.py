class Solution:
    def zeroFilledSubarray(self, nums: List[int]) -> int:
        c = 0
        d = []
        nums.append(1)
        for i in range(len(nums)):
            if nums[i]==0:
                c+= 1
            else:
                if c==0: continue
                d.append(c)
                c = 0
        ans = 0
        for i in d:
            ans+=i*(i+1)//2
        return ans