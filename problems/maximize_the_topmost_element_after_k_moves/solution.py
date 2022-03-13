class Solution:
    def maximumTop(self, nums: List[int], k: int) -> int:
        if k==0:
            return nums[0]
    
        n =len(nums)
        
        if n==1:
            if k&1:
                return -1
            else:
                return nums[0]
            
        if k==1:
            return nums[1]
        
        if k > n:
            return(max(nums))
        if k==n:
            return max(nums[:k-1])
        else:
            x = max(nums[:k-1])
            # print(nums[:k-1])
            # print(x)
            return (max(x,nums[k]))