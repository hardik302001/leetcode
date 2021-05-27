class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        k=len(nums)
        nums.sort()

        res=[]
    
        target = 0
        for i in range(0,k-2):
            start=i+1
            end=k-1
            
            while start < end:
                cur = nums[i]
                cur = cur + nums[start] + nums[end]
                if cur==target and [nums[i],nums[start],nums[end]] not in res: 
                    res.append([nums[i],nums[start],nums[end]])
                    start+=1
                    end-=1
                elif cur > target:
                    end-=1
                else:
                    start+=1
        return res