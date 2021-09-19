class Solution:
    def sumOfBeauties(self, nums: List[int]) -> int:
        ma = []
        mi = []
        
        mii = 1000000
        maa = 0
        for i in nums:
            # mii = min(mii,i)
            maa = max(maa,i)
            ma.append(maa)
            # mi.append(mii)
        p = nums[::-1]
        for i in p:
            mii = min(mii, i)
            mi.append(mii)
        mi = mi[::-1]
        # print(ma)
        # print(mi)
        n = len(nums)
        c = 0
        for i in range(1,n-1):
            # print(ma[i-1],nums[i],mi[i+1])
            if ma[i-1]<nums[i] and nums[i]<mi[i+1]:
                c =c +2
            elif nums[i-1] < nums[i]  and nums[i]<nums[i+1]:
                c =c +1
        return c