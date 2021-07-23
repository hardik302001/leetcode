class Solution:

    # one pass 
    def sortColors(self, nums):
        # zero and r record the position of "0" and "2" respectively
        l, r, zero = 0, len(nums)-1, 0
        while l <= r:
            if nums[l] == 0:
                nums[l], nums[zero] = nums[zero], nums[l]
                l += 1; zero += 1
            elif nums[l] == 2:
                nums[l], nums[r] = nums[r], nums[l]
                r -= 1
            else:
                l += 1
                
'''
    # count sort    
    def sortColors(self, nums):
        c0 = c1 = c2 = 0
        for num in nums:
            if num == 0:
                c0 += 1
            elif num == 1:
                c1 += 1
            else:
                c2 += 1
        nums[:c0] = [0] * c0
        nums[c0:c0+c1] = [1] * c1
        nums[c0+c1:] = [2] * c2
'''