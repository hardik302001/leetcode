#monotonic function
#binary serach O(nlogn)
#more the value of divisor considered, less the number of sum we get
#so monotonic, we can apply bs..

#EXACTLY SAME AS :  https://leetcode.com/problems/koko-eating-bananas/submissions/





class Solution:
    def smallestDivisor(self, nums: List[int], threshold: int) -> int:
        lo,hi = 1 , max(nums)         #low when all elements equal (or) 1     #high can be atmax max(quan) bcz we need to minimise maximum
        while lo < hi:
            mid = (lo + hi) // 2
            if self.lessThanThreshold(mid, nums, threshold):
                hi = mid
            else:
                lo = mid + 1
        return lo
    
    
    
    def lessThanThreshold(self,k, nums, threshold):                         #if we can take all products
        sum = 0
        for i in range(len(nums)):
            sum += int(math.ceil(nums[i]/int(k)))    #to conisder how many stores will quan[i] take, if we can have atmost k products in each store
            
            if sum > threshold: return False       #k is too small, less k leads to more number of stores
        return True