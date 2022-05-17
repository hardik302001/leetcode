class Solution:

    # one pass 
    def sortColors(self, nums):
        # zero and r record the position of "0" and "2" respectively
        l, r, zero = 0, len(nums)-1, 0
        while l <= r:
            if nums[l] == 0:
                nums[l], nums[zero] = nums[zero], nums[l]
                zero += 1
                l = l + 1   # if we get 0, 0 then endless loop.
                
            elif nums[l] == 2:              # we dont need l = l +1 in nums[l]==2, bcz after swapping suppose we get 0 , then that zero would be ignored if we do l = l+1          [1,2,0]
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