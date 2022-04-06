# https://leetcode.com/problems/3sum-with-multiplicity/


class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        k=len(nums)
        nums.sort()

        res=[]
    
        target = 0
        for i in range(0,k-2):
            if(nums[i] > 0):
                break
            start=i+1
            end=k-1
            
            while start < end:
                cur = nums[i] + nums[start] + nums[end]
                if cur==target and [nums[i],nums[start],nums[end]] not in res: 
                    while start < end and nums[start] == nums[start+1]:
                        start += 1
                    while start < end and nums[end] == nums[end-1]:
                        end -= 1
                    res.append([nums[i],nums[start],nums[end]])
                    start+=1
                    end-=1
                elif cur > target:
                    end-=1
                else:
                    start+=1
        return res